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

