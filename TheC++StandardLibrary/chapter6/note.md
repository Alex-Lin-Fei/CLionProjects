#STL 组件（component)  
+ 容器（container)  
用来管理某类对象的集合
+ 迭代器(iterator)  
用来在一个对象集合中遍历元素
+ 算法(algorithm)  
用来处理集合内部的元素，可以出于不同目的查找、排序、修改、使用元素
#容器(container)  
三大类  
+ 序列式容器（sequence container)
这是一种有序（ordered)集合，其内每个元素均有确凿的位置——取决于插入时机与地点，包括：array、vector、deque、list、  
  forward_list，通常被实现为array或linked list  
  
+关联式容器（associative container)  
已排序（sorted)集合，元素位置取决于其value或key和给定的排序准则，与插入次序无关，包括：set、multiset、map、multimap  
通常被实现为binary tree  

+ 无序容器(unordered container)  
这是一种无序集合，每个元素的位置无关紧要，唯一重要的三某个特定元素是否位于集合内。而且元素的位置可能在容器生命中被改变，  
  次序不明确，且可能随着时间而改变，包括：unordered_set、unordered_multiset、unordered_map、unordered_multimap
  通常被实现为hash table  
  
##序列式容器  
###vector  
vector将其元素置于一个dynamic array中管理，允许随即访问，可以利用索引直接访问任何一个元素，在array尾部附加元素或移除元素都很快  

###deque  
是一个dynamic array，可以向两端发展，因此在头部和尾部安插元素都十分迅速  

###array  
```c++
array<int, 5> nums{} ;
    for (auto& i: nums)
        cout << i << ' ';
    cout << endl;
```
默认情况下，这些元素都会被default构造函数初始化，意味着对于基础类型，初值不明确（undefined)  
可使用初值列初始化，基础类型使用zero initialization  

###List  
由双向链表实现而成，任何位置安插或删除动作都非常迅速  

###forward list  
单向链表  

##关联式容器associative container  
关联式容器依据特定的排序准则，通常由二叉树实现  
###Set  
元素依据value自动排序，每个元素只能出现一次  
###multiset  
元素可以重复  
###map  
每个元素都是key/value pair，其中key是排序准则的基准，每个key只能出现一次  
###multimap   
元素可以重复，即允许其元素拥有相同的key  

##无序容器（unordered container）  
在无序容器中，元素没有明确的排序次序，也就是，如果安插3个元素，每次迭代容器中的所有元素时，会发现，次序各有可能，  
如果安插第四个元素，前三个元素的相对次序可能改变，我们唯一关心的是，某个特定的元素是否在容器内。  
任何安插动作都可能改变上述次序。事实上任何操作只要可能引发rehashing就可能改变上述次序  

##其他容器  
String  

##容器适配器 （container adapter)  
预定义容器，提供的是一定限度的接口，用以应付特殊需求，这些容器适配器都是根据基本容器实现的，包括  
+ stack  
+ queue  
+ priority queue  

#迭代器（iterator)  
概念：以一个对象表现出容器元素的位置。  
基本操作： 
+ operator *  
返回当前位置的元素值  
  
+ operator ++   
令迭代器前进至下一元素，大多数迭代器还可使用operator--退至前一元素 
  
+ operator == 和 != 判断迭代器是否指向同一位置  
+ operator = 对迭代器进行赋值（指明迭代器所指向的位置）  

迭代器内部运作机制取决于其所遍历的数据结构，每一种容器都提供了自己的迭代器，事实上每一种容器的确都将其迭代器以嵌套  
的方式定义于class内部，各种迭代器接口虽然相同，类型各不相同  
所有容器类都提供一些基本的成员函数，最重要的有：
+ begin()返回一个迭代器，指向容器起点，也就是第一个元素位置  
+ end()返回一个迭代器，指向容器终点，位于最末元素的下一位置，又称为逾尾迭代器  
于是begin()和end()形成了一个半开区间
  
任何容器都定义两种迭代器类型：  
+ container::iterator 以**读/写**模式遍历元素  
+ container::const_iterator 以**只读**模式遍历元素  
**note**：前置式递增比后置式递增效率高，后者内部需要一个临时对象，因为它必须存放迭代器原本的位置并返回  
  
##cbegin() 和 cend()  
自c++11开始，我们可以使用关键字auto代替迭代器的精确类型（前提是迭代器在声明期间就被初始化，使其类型可以取决于初值）  
**优点**：  
+ 程序比较浓缩精简  
+ 万一容器类型有所改变，程序整体仍然能保持较佳健壮性  
**缺点**：
+  会使得pos成为一个非常量迭代器，因为begin()返回的是类型为cont::iterator的对象  
如下代码：
```c++

void testIterator() {
    list<char> cls{'a', 'b', 'c', 'd'};

    list<char>::const_iterator pos;
    for (pos = cls.begin(); pos != cls.end(); pos++) {
        *pos = *pos + 1; //ERROR
        cout << *pos<<' ';
    }
    cout << endl;

}
```

##关联式及无序式容器的实例  
使用c++11之前的set  
```c++

int main() {
typedef std::set<int> IntSet;

IntSet coll;

coll.insert(3);
    coll.insert(1);
    coll.insert(5);
    coll.insert(4);
    coll.insert(1);
    coll.insert(6);
    coll.insert(2);

    IntSet::const_iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos<<' ';
    }

    cout << endl;

    return 0;
}

```
unordered_multiset  
元素的顺序是不明确的，取决于hash table的内部布局，也取决于hashing函数，唯一可保证的是，内容相同的元素会相邻  


##迭代器种类  
以下三类  
+ 前向迭代器forward iterator。只能以累加操作符向前迭代，如forward_list。unordered_set、unordered_multiset
  、unordered_map、unordered_multimap也都至少是此类别
+ 双向迭代器bidirectional iterator。顾名思义可以双向进行：以递增运算前进或以递减运算后退。list、set、multiset、map
  、multimap提供的迭代器都属于此类  
+ 随即访问迭代器random_access iterator。不但具备双向迭代器的所有属性，还具备随机访问的能力，提供了迭代器算术运算的必要操作符
。可以增加或减少一个偏移量、计算两个迭代器之间的距离、进行<或>比较，如vector、deque、array、string提供的迭代器  

两个类别  
+ 输入型迭代器input iterator。向前迭代时可以读取/处理value
+ 输出型迭代器output iterator。向前迭代时能涂写value

可以将非常量迭代器赋值给常量迭代器  
```c
    vector<int>::iterator p = x.begin();
    vector<int>::const_iterator cp = p;
    cout << &p << ' ' << endl;
    cout << &cp<<' ' <<endl;
    //console
0x7ffd999a5370
0x7ffd999a5378 
两迭代器地址不同,且只有p的值可以被改变
```

#算法Algorithm  
**note**: 排序函数sort与反转函数reverse均会改变元素的value,因此需传入非常量迭代器,不能传入cbegin(),cend(),如  
```c
    vector<int> x {1,2,4,3,45,6}; 
    sort(x.begin(), x.end()); //OK
    sort(x.cbegin(), x.cend());//RUNTIME ERROR
    reverse(x.cbegin(), x.cend());//RUNTIME ERROR
    reverse(x.begin(),x.end());//OK
```
##处理多重区间multiple ranges  
有数个算法可以同时处理多重区间,通常你必须设定第一个区间的起点和终点,至于其他区间,只需设定起点即可,终点通常可以由第一个区间元素数量推导出来  
```c
if (equal(coll1.begin(), coll1.end(), coll2.begin()) {
    
}
```
**note**: 如果某个算法用来处理多重区间,那么当你调用它时,必须确保第二个(以及其他)区间所拥有的元素个数至少和第一个区间的元素个数相同
例如:
```c
    list<int> coll1{1,2,3,4,5};
    vector<int> coll2;
//RUNTIME ERROR
    copy(coll1.begin(), coll1.end(), coll2.begin());
```
由于该算法执行的是覆写动作而非安插,可以修正  
+ 确认目标区间有足够的元素空间  
+ 采用insert iterator  

#迭代器之适配器(iterator adapter)  
迭代器iterator是一个纯抽象概念,任何东西,只要其行为类似迭代器,它就是一个迭代器  
迭代器适配器类型  
+ insert iterator(安插型)
+ stream iterator(串流型)
+ reverse iterator(逆向)
+ move iterator(搬迁)

##安插型迭代器  
inserter,它可以使算法以安插方式而非覆写方式运作,可以解决算法的目标空间不足问题,促使目标区间的大小按照需要增长  
示例代码:  
```c
 list<int> coll1 = {1,2,3,4,5};

    vector<int> coll2;
    copy(coll1.begin(), coll1.end(), back_inserter(coll2));

    deque<int> coll3;
    copy(coll1.begin(), coll1.end(), front_inserter(coll3));

    set<int> coll4;
    copy(coll1.begin(), coll1.end(), inserter(coll4, coll4.begin()));
```

三种预定义的insert iterator:  
+ back inserter(安插于容器最末端),使用push_back(val)在尾部插入元素,表达式back_inserter(container)
+ front inserter(安插于容器最前端),使用push_front(val)在容器前端插入元素,表达式front_inserter(container)
+ general inserter(一般性的inserter, 指的是在初始化时接受之第二个实参所指的位置的前方插入元素),使用insert(pos, val)在pos位置安插元素,表达式inserter(container, pos)  

##串流迭代器  
示例代码:  
```c
vector<int> coll;

    copy(istream_iterator<int>(cin),
            istream_iterator<int>(),
         back_inserter(coll));

    sort(coll.begin(), coll.end());

    unique_copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, "\n"));
    //console
3 1 65 2 21 4l
1
2
3
4
21
65
```
**note**:输入一个非指定类型的数据才会停止输入

##反向迭代器  
reverse iterator会造成算法逆向操作,其内部对increment操作符的调用转换为对decrement操作符的调用,反之亦然  
所有提供双向或随即访问迭代器的容器(也就是forward_list之外的所有序列式容器和所有关联式容器)都可以通过成员函数rbegin()和rend()产生一个反向迭代器  
还有只读反向迭代器crbegin() ,crend()  

##move iterator  
参见page216