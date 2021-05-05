#auto
以auto声明的变量，其类型会根据其初值被自动推导，一定需要
一个初始化操作  
```c++
auto i; //ERROR   
```
如果类型很长或者表达式很复杂，auto非常有用

#uniform initialization 
面对任何初始化动作，可以使用相同的语法——大括号{}  
某个local变量属于某种基础类型会被初始化为0/nullptr  
narrowing 窄化——精度降低或者数值变动——对{}是不成立的(error)  
(参见function a)

#initializer list
提供class template std::initializer_list<>支持一系列值(a list of value)  
进行初始化(参见function print)
当指明实参个数 和 指明一个初值列 的构造函数（ctor）同时存在，带有初值列那个优先(参见class P)
```c++

class P {
public:
P(int, int) {
std::cout << "this is (int, int)\n";
}
P(std::initializer_list<int>) {
std::cout << "this is initializer list"<<std::endl;
}
};

int main() {
P p(77,5);
P q{77,5};
P r{77,5, 3};
P s = {77,5};
}

//console
this is (int, int)
this is initializer list
this is initializer list
this is initializer list

Process finished with exit code 0
```
如果上述带有初值列的构造函数不存在，则q s将被第一个函数初始化，而r初始化无效

#explicit
可令 多数值自动类型转换 不再起作用，即使初始化以=语法进行
```c++
class P {
    public:
    P(int a, int b) {
        ..
    }
    explicit P(int a, int b, int c) {
        ...
    }
};

P x(77, 5); //OK
P y{77, 5}; //OK
P z{77,5,32}; //OK
P v = {77, 5}; // OK(implicit type conversion allowed)
P w = {77, 5, 42}; //ERROR due to explicit (no implicit type conversion allowed)

void fp(const P&);

fp({47, 11}); //OK, implicit conversion of {47, 11} into P
fp({47, 11, 3}); //ERROR due to explicit
fp(P{47, 11}); //OK explicit conversion of {47, 11} into P
fp(P{47, 11, 3}); //OK explicit conversion of {47, 11, 3} into P
```

同样地，explicit构造函数如果接受的是初值列，会失去 初值列带有0个，1个，2个或多个初值 的隐式转换功能
#Range-Based for 循环
一般性语法：
```c++
for (decl: coll) {
    statement
}
```

等同于
```c++
for (auto _pos = coll.begi(); _end=coll.end(); _pos!=end; ++_pos) {
    decl = *_pos;
    statement
}
```
同时甚至可以针对初值列(initializer list) 使用range-based for 循环，因为std:initializer_list<>  
提供了成员函数begin()与成员end()
此外，允许使用寻常的、大小已知的C-style array，例如：
```c++
int array[] = {1,2,3};

long sum = 0;
for (int x: array) 
    sum += x;
for (auto elem: {sum, sum*2, sum*4})
    cout << elem<<endl;
```

注意！！！当元素在for循环中初始化为del时，不允许任何显式类型初始化（explicit type conversion）：
```c++
class C {
    public:
    explicit C(const std::string& s);
};

std::vector<std::string> vs;
for (const C&elem: vs) { // ERROR: explicit type conversion from strings
    std::cout << elem<<std::endl;
}
```

#Move语义和Rvalue Reference
c++11最重要的一个特性就是，支持move semantic(搬迁语义)，避免非必要拷贝copy和临时对象(temporary)
```c++
X x;
coll.insert(x); //inserts copy of x
coll.insert(x+x); //inserts copy of temporary rvalue
coll.insert(x); //inserts copy of x (although x is not used any longer

coll.insert(std::move(x)); //moves(or copies) contents of temporary of x into coll
```
有了声明与<utility>的std::move()，x可被move而不再被copied，然而std::move()自身并不做任何moving的工作，它只是将其参数转成一个所谓的rvalue reference
即X&&类型。含义三：这是个不再需要的（临时）对象，所以可以偷其内容和资源  
例如，string的move构造函数只是将既有的内部字符串赋予新对象，而非建立一个新array然后复制所有元素；同样，对于所有集合class，不再为所有元素建立一份拷贝，只需
要将内部内存赋予新对象即可。

#Rvalue和Lvalue Reference的重载规则
+ 如果只实现了  
```c++
void foo(X&);
```
而没有实现
```c++
void foo(X&&);
```
foo可因lvalue但不能因rvalue调用  
+ 如果实现了
```c++
void foo(const X&);
```
而没有实现
```c++
void foo(X&&);
```
foo可因lvalue也可因rvalue调用
+ 如果实现了
```c++
void foo(X&);
void foo(X&&);
```
或者
```c++
void foo(const X&);
void foo(X&&);
```
可以区分 为rvalue服务 和 为lvalue服务
+ 如果实现了
```c++
void foo(X&&);
```
而没有void foo(X&) 和 void foo(const X&)，则只可因rvalue被调用

#noexcept
关键字noexcept用来指明某个函数无法——或不打算抛出异常（page24)

#constexpr
可让表达式核定于编译期，详见page26

#Template
+ Variadic Template
```c++
void print() {
    
}

template<typename T, typename...Types>
void print(const T& firstArg, const Types&... args) {
    std::cout << firstArg<<std::endl;
    print(args...);
}
```
+ Alias Template
```c++
template <typename T>
using Vec = std::vector<T, MyAlloc<T>>;
```
后，Vec<int> coll;
等价于
```c++
std::vector<int, MyAlloc<int>> coll;
```

#Lambda
##语法
所谓lambda是一份功能定义式，可被定义于语句(statement)和表达式(expression)  
最小型的lambda函数没有参数，如下：
```c++
[] {
    std::cout << "hello, world" <<std::endl;
}
```
也可以直接调用：
```c++
[] {
    std::cout << "hello, world" <<std::endl;
}();
```
或者传递给对象，使之可以被调用：
```c++
auto l = [] {
std::cout << "hello, lambda" << std::endl;
};
l();
```
lambda可以拥有参数，指明于小括号内，就像任何函数一样
```c++
auto l = [](const std::string& s) {
    std::cout << s << std::endl;
};
l("Hello");
```
然而，lambda不可以是template，必须始终指明所有类型！！！
lambda也可以有返回值，但不需要指明返回类型，该类型会根据返回值被推导出
```c++
[] {
    return 1;
};
```
也可以使用新式语法，一般函数也可以用到
```c++
[]() -> int {
return 1;
};
```
##Capture
在lambda introducer(开始的方括号内)，你可以指明一个capture用来处理外部作用域内未被传递为实参的数据  
+ = 意味着外部作用域以by value的方式传递给lambda，因此可以读取但不能改动
+ & 意味着外部作用域以by reference方式传递给lambda，因此拥有读写的权限
也可以分别指明lambda之内你所访问的每一个对象是by value或by reference  
```c++
int x = 0;
int y = 42;
auto qqq = [x, &y] {
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    ++y;
};
x = y = 77;
qqq();
qqq();
std::cout << "final y: " << y << std::endl;

//console
x: 0
y: 77
x:0
y::78
final y: 79
```
因为x获得的是一份拷贝（即0），在此lambda内部无法改动（如赋值，自增加自减等）  
y获得的是引用，因此可以改变，其值会影响外部  
为了获得passing by value 和passing by reference 的混合体，可以声明lambda为mutable  
对象以by value的方式传递，在这个lambda内部可以改动它，但结果不会影响外部    
```c++
int id = 0;
auto f = [id] () mutable {
    std::cout << "id: " << id << std::endl;
    ++id; //OK
};
id = 42;
f();
f();
f();
std::cout << id << std::endl;

//console
id: 0
id: 1
id: 2
42
```
可以把上述lambda视为以下function object  
```c++
class {
    private:
    int id;
    public:
    void operator()() {
        std::cout << "id: " << id << std::endl;
        ++id;
    }
};
```
由于mutable的缘故，operator()()被定义为一个non-const成员函数，若没有mutable，operator()为一个const函数  

##Lambda的类型  
lambda的类型是个不具名的function object，每个lambda表达式的类型三独一无二的  
可以使用std::function<>class template  
```c++
std::function<int(int, int)> returnLambda () {
    return [](int x, int y) {
        return x*y;
    };
}

int main() {
    auto lf = reurnLambda();
    std::cout << lf(4,5) << std::endl; //20
}
```

#关键字 decltype  
参见page 32  
#enum class  
参见page 32  
#Template  
##Default Template Parameter  
class template可以拥有默认实参，例如   
```c++
template <typename T, typename container = vector<T>>
class MyClass;
```
如果只传入一个实参，则第二个实参采用默认值，即vector<T>  
```c++
MyClass<int> x1; //<int, vector<int>>
```
反之
```c++
MyClass<int, float> x1; //<int, float>
```
详见page33
#基础类型的明确初始化  
如果使用了一个明确的构造函数调用但不给实参，基础类型会被设定为初值0  
```c++
int i; //undefined value
int i2 = int(); //initialized with zero
int i3{}; //initialized with zero
```
初始化机制确保了如果x为基础类型，则会被初始化为0  
```c++
template <typename T>
void f() {
    T x = T();
}
```
如果template强迫设置初值0,即zero initialized，否则就是default initialized






