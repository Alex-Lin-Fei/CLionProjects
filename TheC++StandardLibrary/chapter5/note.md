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






