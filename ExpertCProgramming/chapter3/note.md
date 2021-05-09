如果想要把什么东西的类型强制转换为指向数组的指针，就不得不使用下面的语句来表示这个强制类型转换  
```c
char (*j)[20]; //j是一个指向数组的指针，数组内有20个char元素
j = (char (*)[20])malloc(20);
```
union的优点  
有些数据项是不可能同时出现的，如果想同时存储他们，显得颇为浪费。例如，要存储一些关于动物种类的信息，首先想到的是  
```c
struct creature {
    char has_backbone;
    char has_fur;
    short num_of_legs_in_excess_of_4;
};

```

但是，我们知道，所有动物要么是脊椎动物，要么是无脊椎动物。进而，只有脊椎动物才可能有毛发，而无脊椎动物可能有多于4条的腿，因此将  
两个相互排斥的字段存储于一个联合中：  
```c
union secondary_characteristics {
char has_fur;
short num_of_legs_in_excess_of_4;
};

struct creature {
    char has_backbone;
    union secondary_characteristics form;
};
```

联合体还可以把同一种数据解释成不同的东西，如：  
```c
union bigs_32_tag {
    int whole;                           //一个32位的值
    struct {char c0, c1, c2, c3; } byte; //4个8位字节
};
```

c语言声明优先级规则  
A 声明从它的名字开始读取，然后按照优先级顺序依次读取。  
B 优先级从高到低依次是：  
  B. 1  声明中被括号括起来的那部分  
  B. 2  后缀操作符：  
        括号()表示这是一个函数，而方括号[]表示这是一个数组
  B. 3  然后，处理前缀"*"，得出指针所指的内容
C 如果const和（或）volatile关键字的后面紧跟类型说明符（如int，long），那么它作用于类型说明符，在其他情况下作用与左边紧邻的指针星号  

示例：  
```c
char* const *(*next)()
//next是一个指针，它指向一个函数，该函数返回另外一个指针，该指针指向一个类型为char的常量指针
```
还可参考开头的j指针，指向一个数组  

typedef int x[10] 和#define x int[10] 的区别  
+ 可以用其他类型说明符对宏类型名进行扩展，但对typedef所定义的类型名不能  
```c
#define peach int
unsigned peach i; //OK
typedef int banana;
unsigned banana i; //ERROR
```
+ 在连续几个变量声明中，用typedef定义的类型能够确保声明中所有变量均为用一种类型，而#define定义的类型无法保证  
```c
#define int_ptr int *;
int_ptr chalk, cheese; //== int * chalk, cheese chalk为指向int的指针，而cheese则是一个int
typedef char * char_ptr;
char_ptr Bentley, Eolls_Royce; //类型均为指向char的指针

```

结构标签与结构类型  
```c
typedef struct fruit {...} fruit; //语句1
struct veg {...} veg; //语句2


//语句1声明了结构标签fruit和typedef声明的结构类型“fruit”
struct fruit mandarin; //使用结构标签“fruit”
fruit mandarin; //使用结构类型"fruit"

//语句2声明了结构标签”veg"和变量veg只有结构标签能够使用, 注意veg是一个变量
struct veg potato;
```


