#c++中的通用工具  
##Pair/tuple
###Pair  
事实上pair是个struct而不是class，因此所有成员都是public  
```c++
namespace std {
    template <typename T1, typename T2>
    struct pair {
        T1 first;
        T2 second;
    };
}
```
具体使用方法见page61

###Tuple  
声明：  
```c++
namespace std {
    template <typename... Types>
    class tuple;
}
```
tuple拥有任意数量的元素，呈现出一个异质元素列，   
其中每个类型都是可以被指定的，或来自编译器推导  
+ 操作  
通过明白的声明，或者make_tuple()，可以创建一个tuple   
  通过get<>()function template，可访问元素  
  （实例见page69）
  
tuple的使用见page71

+ make_tuple/tie()
```c++
std::tuple<int, float, std::string> t(77, 1.1, "more light");
int i;
float f;
std::string s;
std::tie(i,f,s) = t;
std::cout << i << ' ' << f << ' ' << s << ' ' << std::endl;
s = "change";
std::cout << std::get<2>(t)<<std::endl;
std::get<2>(t) = "aaa";
std::cout << std::get<2>(t)<<std::endl;
std::cout << s <<std::endl;

//console
77 1.1 more light
more light
aaa
change
```
这里tie()会以i、f、s的reference建立一个tuple，将t内元素分别赋值i、f、s  
允许std::ignore忽略tuple的某些元素  
```c++
std::tuple<int, float> t(1,2);
int i;
float j;
std::tie(i, std::ignore) = t;
```
+ tuple和初值列  
接受不定个数的参数的版本被声明为explicit  
```c++
namespace std {
    template< typename... Types>
    class tuple {
        public:
        explicit tuple(const Types&...);
        template<typename... UTypes> explicit tuple(UTypes&&...);
    };
}

//避免单一值被隐式转换为仅有一个元素的tuple
template <typyname... Args>
void foo(const std::tuple<Args...> t);

foo(42); //ERROR explicit conversion to tuple<> required
foo(make_tuple(42)); //OK

```
不过目前c++已经支持隐式转换了貌似，如下：
```c++

std::tuple<int> testInitializerList() {
    return {1};
} //此段代码并不报错
```
###其他的tuple特性  
参见page73  

##Smart Pointer
即智能指针  
指针存在的问题：  
确保pointer的寿命和其所指向的对象的寿命一致。特别是当多个pointer指向同一对象时，其中一个  
pointer销毁时不该出现所谓的空悬指针或多次删除被指向的对象，造成资源泄露  

两大类型smart pointer:
+ Class shared_ptr 实现**共享式拥有（shared ownership)**。多个smart pointer可以指向相同的对象，  
该对象和其相关资源会在**最后一个reference被销毁**时被释放

+ Class unique_ptr实现**独占式拥有（exclusive ownership）**，保证同一时间内只有一个smart pointer  
可以指向该对象，可以移交拥有权。适用于**避免资源泄露——以new创建对象后发生异常而忘记调用delete**  
  
###shared_ptr
多个shared_ptr可以共享一个对象，对象的最末一个拥有者有责任销毁对象，并清理与该对象相关的所有资源  
参见testSharedPointer函数  
**note**: 由于就接受单一pointer作为唯一实参的构造函数是explicit，所以无法使用赋值符，因为那样  
被视为需要一个隐式转换  
```c++
shared_ptr<string> pNico = new string("xx"); //ERROR
shared_ptr<string> pNico{new string("xx")}; //OK
shared_ptr<string> pNico = make_shared<string>("xx"); //OK
shared_ptr<string> pNico;
pNico.reset(new string("xxx")); //OK
```
但凡容器，总是为传入的元素创建属于容器自己的拷贝  
use_count()会产出 某个shared_ptr所指向对象的当前拥有者数量。程序终点处，当string的最末一个拥有者被销毁，shared pointer  
对其所指向的对象调用delete，并非一定发生在作用域终点。  
我们也可以自定义一个deleter  
```c++
shared_ptr<string> pNico(new string("nice"), [](string* p) {
    cout << "delete " << *p << endl;
    delete p;
});
```
**note**: shared_ptr提供的default deleter 是delete，不是delete[]，因此当为array建立一个shared_ptr需要定义自己的deleter。  
其内调用delete[]  
```c++
//自定义deleter，传入一个函数、函数对象或者lambda  
shared_ptr<int> p(new int[10], [](int * p) {
    delete[] p; 
});
//使用为unique_ptr提供的辅助函数
shared_ptr<int> p(new int[10], std::default_delete<int[]>());

//对于unique_ptr，必须明确给予第二个template实参，指出你自己的deleter 
unique_ptr<int, void(*)(int*)> p(new int[10], [](int* p) {
    delete[] p;
});
```



###weak_ptr
shared_ptr存在的问题：  
+ 环式指向  
+ 明确想共享但不愿拥有某对象的情况下  
详见page85以及testWeakPtr函数
  
###误用shared pointer
必须确保某对象只被一组shared pointer拥有  
```c++
int * p = new int;
shared_ptr<int> sp1(p);
shared_ptr<int> sp2(p); //ERROR, two shared pointers manage allocted int
```
sp1 sp2都会在丢失p的拥有权时释放相应资源  
```c++
shared_ptr<int> sp1(new int);
shared_ptr<int> sp1(sp1);
```

###unique_ptr  
实现了独占式拥有的概念，可以确保一个对象和其相应资源同一时间只被一个pointer拥有，一旦拥有者  
被销毁或变成empty，或开始拥有另一个对象，先前拥有的那个对象就会被销毁，其相应资源都会被释放  
必须直接初始化  
```c++
unique_ptr<int> up = new int; //ERROR
unique_ptr<int> up（new int); //OK
```
可以对它赋予nullptr或者调用reset()  
```c++
up = nullptr;
up.reset();
```
可以调用release获得unique_ptr拥有的对象并放弃拥有权  
```c++
string* p = up.release();
```

检查是否unique_ptr拥有对象  
```c++
if(up) {} // 调用bool()
if (up != nullptr) {} //与nullptr对比
if (up.get() != nullptr) {} //
```
移转unique_ptr的拥有权  
不能执行copy和assign  
考虑这样使用copy：
```c++
unique_ptr<Class> up1(new Class);

unique_ptr<Class> up2(up1); //ERROR
unique_ptr<Class> up2(std::move(up1)); //OK
```
考虑这样使用assign  
```c++
unique_ptr<Class> up1(new Class);

unique_ptr<Class> up2;
up2 = up1;//ERROR
up2 = std::move(up1); //OK
```
如果赋值之前up2原本拥有对象，则会有一个delete的动作  
失去对象拥有权的unique_ptr并不会得到一个指向无物的新拥有权，如果想指派新值给unique_ptr，  
必须是一个unique_ptr或者nullptr  
```c++
unique_ptr<Class> up;
up = new Class; //ERROR;
up = unique_ptr<Class>(new Class); //OK delete old object
```
函数可以利用它们将拥有权转移给其他函数  
+ 函数是**接收端**  
```c++
void sink(unique_ptr<Class> up) {
    
}

unique_ptr<Class> up(new Class);
sink(std::move(up)); //up loses ownership
```
+ 函数是**供应端**  
```c++
unique_ptr<Class> source() {
    unique_ptr<Class> ptr(new Class);
    return ptr; //
}

void g() {
    unique_ptr<Class> p;
    
    for (int i = 0; i < 10; i++) {
        p = source();
    }
}
```
每当source()被调用，会以new创建对象并返回给调用者，夹带着其拥有权。返回者被赋值给p，  
拥有权也被转移给p。在第二次循环中，对p的赋值导致p先前拥有的对象被删除，一旦g结束，p  
被销毁，导致最后一个由p拥有的对象被析构，无论如何都不会发生资源泄露  
**note**: return 不需要std::move的原因是，c++11规定，编译器自动尝试添加move  

unique_ptr被当做成员  
在class内使用unique_ptr可避免资源泄露。如果使用unique_ptr取代寻常的pointer，就不再需要析构函数，因为对象被删除会连带所有成员被删除  
此外unique_ptr也可以协助避免“对象初始化期间因抛出异常而造成资源泄露”。  
**note**: 只有当一切构造动作都完成了，析构函数才能被调用，所以，对于“拥有多个raw pointer”的class，如果构造期间第一个new成功而第二个失败，  
就可能造成资源泄露。  

对于array：  
参见函数testUniquePtrArray  

```c++
void testUniquePtrArray() {
    unique_ptr<string[]> up(new string[10]);
    up[0] = "hello";
    cout << *up <<endl;  //ERROR
    cout << up[0] << endl; //OK
}
```
**note**:这个class起不了派生类型的array作为初值  

##deleter  
当你所指的对象要求的不止是调用delete或者delete[]，可具体制定自定义的deleter。然而，此处deleter的定义方式不同于shared_ptr   
必须指明deleter的类型作为第二个template实参。该类型可以是个reference to function或者function pointer或者function object  
若是个function object，其function call操作符()应该接受一个指向对象的pointer  
```c++
class ClassADeleter {
    public:
    void operator()(ClassA* p) {
        cout << "call delete for class A" << endl;
        delete p;
    }
};

unique_ptr<ClassA, ClassADeleter> up(new ClassA);
```

如果你给的是个函数或者lambda，必须声明deleter的类型为void(*)(T*)或者function<void(T*)>，或者decltype  
```c++
//void(*)(T*)  
unique_ptr<int, void(*)(int*)> up(new int[10], [](int* p) {
    delete[] p;
});

//function<void(int*)>
unique_ptr<int, function<void(int*)> up(new int[10], [](int* p) {
delete[] p;
});

//decltype
auto l =  [](int* p) {
delete[] p;
};

unique_ptr<int, decltype(l)> up(new int[10], l);
```
###auto_ptr  
存在非自觉遗失拥有权  
```c++
temeplate<typename T>
void bad_print(auto_ptr<T> p) {
    if (p.get() != nullptr) {
        cout << *p<<endl;
    }
}

int main() {
    auto_ptr<int>p(new int);
    *p = 0;
    bad_print(p);
    *p = 9; //RUNTIME ERROR
}
```
**note**: 一般而言，smart pointer并非线程安全，虽然她适用某些保证  

