#容器的共通能力和共通操作  
##共通能力  
+ 所有容器提供的都是"value语义"而非"reference语义".容器进行安插动作时,内部实施的是copy和/或move动作,而不是管理元素的reference    
+ 元素在容器内有其特定顺序
+ 一般而言,各项操作并非绝对安全,并不会检查每一个可能发生的错误,通常stl自己不会抛出异常  

##共通操作  
###初始化initialization  
详见page255  
  
###赋值assignment和swap()  
当你对着容器赋予元素时,来源容器中的所有元素被复制到目标容器中,后者原本的元素全被移除,代价高昂.可以使用move assignment操作符,针对rvalue而声明,其内部行为只是将pointer(指向value所在之内存)交换而已,并不复制value,赋值左侧容器将拥有右侧容器的所有元素,至于右侧容器,则不明确
```c
vector<int> v1;
vector<int> v2;
v2 = std::move(v1);
```
使用swap置换两个容器的内容.事实上只是置换若干内部pointer,它们被用来指向数据  

###与大小相关的操作函数(size operation)
所有容器都提供三个与大小相关的操作函数  
+ empty()是size == 0的快捷方式,且更有效率  
+ size()返回当前容器的元素数量  
+ max_size()返回容器所能容纳的最大数量,通常返回索引类型的最大值  

###比较comparison  
除了无序容器,常用的比较操作符==,!= <, <=, >, >都依据以下三个规则定义  
+ 比较动作的两端必须属于同一类型  
+ 如果两个容器的所有元素依序相等,那么这两个容器相等,操作符==用来检查元素是否相等  
+ 采用字典式比较来判断某个容器是否小于另一个容器  
无序容器只定义了==和!=,当容器内的每个元素都在另一个容器内有相等元素,则返回true,次序无关紧要  
  
###元素访问  
如果其他元素被删除,所有容器(除了vector和deque)都保证迭代器以及用以指向元素的reference继续保持有效,对于vector,只有删除点之前的元素才保持有效  
如果你以clear()移除所有元素,对vector,deque,和string而言,任何以end()或cend()返回的逾尾迭代器都可能失效  
如果安插元素,只有list,forward_list和关联容器保证原本的迭代器和用以指向元素的reference继续保持有效.对vector而言,这份保证只有当安插动作不超出容量才成立.至于无序容器,上述保证对于reference一般是成立的,但对迭代器,只有不发生rehashing才成立,而安插后最终元素总数小于bucket个数乘以最大负载系数就不会发生rehashing  

#array  
包覆着一个寻常的static C-style array并提供一个stl容器接口,观念上所谓array是指一系列元素,有着固定大小,因此你无法由增加或移除元素而改变其大小,只允许替换值  
```c
namespace std {
    template<typename T, size_t N>
    class array;
}
```
array可以以以下方式声明:  
```c
array<int, 5> a = {1,2,3,4};
    array<int, 5> b({1,2,3,4,5});
    array<int, 5> c{1,2,3,4,5};
    for (auto& i: a) {
        cout << i << ' ' ;
    }
    cout << endl;

    for (auto& i: b) {
        cout << i << ' ' ;
    }
    cout << endl;

    for (auto& i: c) {
        cout << i << ' ' ;
    }
    cout << endl;
    //console
1 2 3 4 0
1 2 3 4 5
1 2 3 4 5 
```
不足长度的元素默认由其类型的default函数初始化  

##swap和move语义 元素类型与个数)
就像所有其他容器一样,array<>提供swap()操作.因此可以和一个相同类型的容器(元素类型与个数都相同)置换彼此的元素.  
然而,array<>不能仅仅置换内部pointer,因此iterator和reference不会随着元素的置换而改变所指的容器,置换后,iterator和reference指向原本的容器,但指向不同的元素
```c
 array<int, 5> a = {1,2,3,4};
array<int, 5> b({5,4,3,2,1});
//vector<int> a{1,2,3,4,0};
//vector<int> b{5,4,3,2,1};
array<int, 5> c{1,2,3,4,5};
for (auto& i: a) {
cout << i << ' ' ;
}
cout << endl;

for (auto& i: b) {
cout << i << ' ' ;
}
cout << endl;

for (auto& i: c) {
cout << i << ' ' ;
}
cout << endl;

auto pa = a.begin();
auto pb = b.begin();
auto ra = &a[0];
auto rb = &b[0];

cout << "pa: " << &*pa<<endl;
cout << "pb: " << &*pb<<endl;
cout << "ra: " << ra<<endl;
cout << "rb: " << rb<<endl;
cout << "a.begin(): " << &*a.begin()<<endl;
cout << "b.begin(): " << &*b.begin()<<endl;
cout << "*pa: " << *pa<<endl;
cout << "*pb: " << *pb<<endl;
cout << "*ra: " << *ra<<endl;
cout << "*rb: " << *rb<<endl;
cout << "*a.begin(): " << *a.begin()<<endl;
cout << "*b.begin(): " << *b.begin()<<endl;
swap(a, b);
cout << "pa: " << &*pa<<endl;
cout << "pb: " << &*pb<<endl;
cout << "ra: " << ra<<endl;
cout << "rb: " << rb<<endl;
cout << "a.begin(): " << &*a.begin()<<endl;
cout << "b.begin(): " << &*b.begin()<<endl;
cout << "*pa: " << *pa<<endl;
cout << "*pb: " << *pb<<endl;
cout << "*ra: " << *ra<<endl;
cout << "*rb: " << *rb<<endl;
cout << "*a.begin(): " << *a.begin()<<endl;
cout << "*b.begin(): " << *b.begin()<<endl;
    //console 
    1 2 3 4 0
    5 4 3 2 1
    1 2 3 4 5
    pa: 0x7ffdc6275220
    pb: 0x7ffdc6275240
    ra: 0x7ffdc6275220
    rb: 0x7ffdc6275240
    a.begin(): 0x7ffdc6275220
    b.begin(): 0x7ffdc6275240
    *pa: 1
    *pb: 5
    *ra: 1
    *rb: 5
    *a.begin(): 1
    *b.begin(): 5
    pa: 0x7ffdc6275220
    pb: 0x7ffdc6275240
    ra: 0x7ffdc6275220
    rb: 0x7ffdc6275240
    a.begin(): 0x7ffdc6275220
    b.begin(): 0x7ffdc6275240
    *pa: 5
    *pb: 1
    *ra: 5
    *rb: 1
    *a.begin(): 5
    *b.begin(): 1
```
可见容器内迭代器未改变.与之对比,测试vector:
输出结果为:  
```c
//console
1 2 3 4 0
5 4 3 2 1
1 2 3 4 5
pa: 0x5635ec2bbe70
pb: 0x5635ec2bbe90
ra: 0x5635ec2bbe70
rb: 0x5635ec2bbe90
a.begin(): 0x5635ec2bbe70
b.begin(): 0x5635ec2bbe90
*pa: 1
*pb: 5
*ra: 1
*rb: 5
*a.begin(): 1
*b.begin(): 5
pa: 0x5635ec2bbe70
pb: 0x5635ec2bbe90
ra: 0x5635ec2bbe70
rb: 0x5635ec2bbe90
a.begin(): 0x5635ec2bbe90
b.begin(): 0x5635ec2bbe70
*pa: 1
*pb: 5
*ra: 1
*rb: 5
*a.begin(): 5
*b.begin(): 1
```
可见reference和先前赋值的迭代器均未改变指向的地址,而容器内部的迭代器改变了指向位置  
##create/copy/destroy  
参见page263  
##tuple接口  
可以使用表达式tuple_size<>::value取得元素个数,tuple_element<>::type取得某特定元素的类型,get()取得某特定元素  
示例代码:  
```c
typedef array<string, 5> FiveStrings;
FiveStrings f ={"Hello", "world", "nico", "are"};
    cout << tuple_size<FiveStrings>::value<<endl;
    cout << typeid(tuple_element<1, FiveStrings>::type).name()<<endl;
    cout << typeid(std::string).name()<<endl;

    cout << get<1>(f)<<endl;
    //console
5
NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
world
```

#Vector  
本身是"将元素置于dynamic array中管理"的一个抽象概念  
```c++
namespace std {
    template <typename T, typename Allocator = allocator<T>>
            class vector;
}
```
##vector的能力  
vector将元素复制到内部的dynamic array中,元素之间存在一定顺序,是一种有序集合,支持随机访问  

###size capacity  
vector提供以操作大小的函数有size, empty, max_size,另一个与大小有关的函数是capacity, 返回实际能够容纳的元素量,若超出,则有必要重新分配内存  
一旦内存重新分配,vector元素相关的reference, pointer, iterator都会失效  
可以使用reserve保留适当容量或者初始化期间就向构造函数传递额外实参,避免重新分配内存,调用reserve所给的实参小于当前vector的容量,不会引发任何效果  
swap之后原先所有的reference, pointer, iterator都换了指向对象,仍然指向原本位置,即失效  
##vector操作  
参见page273  

##使用示例  

```c
 vector<string> sentence;

    sentence.reserve(5);

    sentence.push_back("Hello, ");
    sentence.insert(sentence.end(), {"how", "are", "you", "?"});

    copy(sentence.cbegin(), sentence.cend(),
         ostream_iterator<string>(cout, " "));

    cout << endl;

    cout << " max_size(): " << sentence.max_size()<<endl;
    cout << " size(): " << sentence.size()<<endl;
    cout << " capacity(): " << sentence.capacity()<<endl;

    auto one = sentence.begin()+1;
    auto two = sentence.begin()+2;
    cout << &*one << ' ' << &*two<<endl;
    cout << *one << ' ' << *two<<endl;
    swap(sentence[1],sentence[2]);
    cout << &*one << ' ' << &*two<<endl;
    cout << *one << ' ' << *two<<endl;

    sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");

    sentence.back() = "!";


    copy(sentence.cbegin(), sentence.cend(),
         ostream_iterator<string>(cout, " "));

    cout << endl;

    cout << " max_size(): " << sentence.max_size()<<endl;
    cout << " size(): " << sentence.size()<<endl;
    cout << " capacity(): " << sentence.capacity()<<endl;
//console
Hello,  how are you ?
max_size(): 576460752303423487
size(): 5
capacity(): 5
0x5619cfd7ce90 0x5619cfd7ceb0
how are
0x5619cfd7ce90 0x5619cfd7ceb0
are how
Hello,  are how you always !
max_size(): 576460752303423487
size(): 6
capacity(): 10
```
容量不足时扩充一倍  

#Deque  
采用dynamic array来管理元素,提供随机访问,但头尾均开放,可以快速安插删除元素  
为了提供这种能力,deque通常实现为一组独立区块,第一区块朝某方向扩展,最末区块朝另一方向扩展.  
##Deque的能力  
与vector相比,功能差异如下:  
+ 两段都可快速安插与移除元素  
+ 访问元素时deque内部结构会多一个间接过程,所以速度会慢一些  
+ 迭代器需要在不同区块间跳转,所以**必须是一个smart pointer而不是寻常的pointer**(**why**)
+ 在内存区块大小有限制的系统中,deque可以内含更多元素,因为他使用不止一块内存  
+ 不支持对内存和容量重新分配时机的控制,在除了两端其他地点插入或删除元素都会导致指向deque元素的任何pinter, reference, iterator失效  
+ 会释放不再需要的内存  

##使用  
参见page284  

#List   
使用一个doubly linked list(双向串列)管理元素  

##list的能力  
+ 不支持随机访问  
+ 任何位置上执行元素插入和移除都非常快  
+ 安插和移除并不会造成指向其他元素的各个pointer reference iterator失效  
##list的操作见page291  
##运用实例  
```c
list<int> list1, list2;

    for (int i = 0; i < 6; i++) {
        list1.push_back(i);
        list2.push_front(i);
    }

    printList(list1, list2);

    list2.splice(find(list2.begin(), list2.end(), 3), list1);

    printList(list1, list2);
    list2.splice(list2.end(), list2, list2.begin());

    printList(list1, list2);

    list2.sort();
    list1 = list2;
    list2.unique();
    printList(list1, list2);

    list1.merge(list2);

    printList(list1, list2);
```
运行结果如下:  
```c
List 1: 0 1 2 3 4 5 
List 2: 5 4 3 2 1 0 

List 1: 
List 2: 5 4 0 1 2 3 4 5 3 2 1 0 

List 1: 
List 2: 4 0 1 2 3 4 5 3 2 1 0 5 

List 1: 0 0 1 1 2 2 3 3 4 4 5 5 
List 2: 0 1 2 3 4 5 

List 1: 0 0 0 1 1 1 2 2 2 3 3 3 4 4 4 5 5 5 
List 2: 

```

#forward list  





