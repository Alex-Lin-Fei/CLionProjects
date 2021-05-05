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
