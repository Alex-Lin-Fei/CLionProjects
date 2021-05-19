#指针和内存  
c程序在编译后,会以三种形式使用内存  
+ 静态/全局内存  
静态声明的变量分配在这里,全局变量也使用这部分内存.这些变量在程序开始运行时分配,直至程序终止时才消失.所有函数都能访问全局变量,静态变量的作用域则局限在定义它们的函数内部  
  
+ 自动内存  
这些变量在函数内部声明,并且在函数被调用时才创建,作用域局限于函数内部,而且生命周期限制在函数执行期间  
  
+ 动态内存  
内存分配在堆上,可以根据需要释放,而且直至释放才消失.指针引用分配的内存,作用域局限于引用内存的指针  
  
**note**: null指针和未初始化的指针不同.未初始化的指针可能包含任何值,而包含NULL的指针则不会引用内存中的任何地址.任何时候都不应该对null指针解引用,因为它不包含合法地址  

##用不用NULL
0的含义随着上下文的变化而变化,有时候可能是整数0,有时候可能又是null指针,0也被重载了  
```c
int num;
    int * pi = 0;
    printf("pi: %p; *pi: %d\n", pi, *pi);

    pi = &num;
    *pi = 0;

    printf("pi: %p; *pi: %d\n", pi, *pi);
```
console输出  
```c
Process finished with exit code 139 (interrupted by signal 11: SIGSEGV) //段错误
```
SIGBUS与SIGSEGV的区别:  
+ SIGBUS(Bus error)意味着指针所对应的地址是有效地址，但总线不能正常使用该指针。通常是未对齐的数据访问所致。
+ SIGSEGV(Segment fault)意味着指针所对应的地址是无效地址，没有物理内存对应该地址。

##void  pointer  
void指针是通用指针，用来存放任何数据类型的引用．　　
具有两个有趣的性质：
+ void指针具有与char指针相同的形式和内存对齐方式　　
+ void指针和别的指针永远不会相等．不过，两个赋值为NULL的void指针是相等的  

任何指针都可以被赋值给void指针,它可以被转换回原来的指针类型,这样的话指针的值和原指针是相等的  
```c
 int num;
    int * pi = &num;
    printf("Value of pi: %p\n", pi);
    void * pv = pi;
    pi = (int *) pv;
    printf("Value of pi: %p\n", pi);
```
运行代码:  
```c
Value of pi: 0x7ffe0c0c3f04
Value of pi: 0x7ffe0c0c3f04
```
**void指针只能用作数据指针,而不能用作函数指针**  
**如果把任意类型指针转换为void指针,那就可以把它转换为不同的指针类型**  

sizeof操作符可以用在void指针上,而不能用在void上,不过实际上运行二者都可    
```c
size_ t size = sizeof(void*); //OK 8
size_ t size = sizeof(void); //OK 1
```
运行输出:  
```c
8 1
```

##全局和静态指针  
指针被声明为全局或者静态,就会在程序启动时被初始化为NULL  

#指针的长度和类型  
在大部分现代平台上,数据指针的长度通常是一样的,与指针类型无关.函数指针长度可能与数据指针长度不同  

##内存模式  
使用指针时经常用到以下四种预定义类型  
+ size_t 用于安全地表示长度    
+ ptrdiff_t  用于处理指针算术运算  
+ intptr_t和uintptr_t   用于存储指针地址  

#指针操作符  
##指针算术运算  
**数据指针**可以执行以下几种算术运算  
+ 给指针加上整数  
+ 从指针减去整数  
+ 两个指针相减  
+ 比较指针 
**函数指针则不一定**
   
###给指针加上整数  
实际上加的数是这个整数和指针数据类型对应字节数的乘积  
```c

#define TYPE short

void print(void * pv) {
    printf("before: %p; after: %p\n", pv, pv+1);
}

//指针算术
void testPointer() {
    TYPE t = 1;
    TYPE * p1 = &t;
print(p1);
printf("%p %p\n", p1, p1+1);
    TYPE type[] = {1,2,3};
    TYPE * p2 = &type[0];
    print(p2);
    printf("%p %p\n", p2, p2+1);
void * pv = p1;
printf("%p %p\n", pv,  pv+1);
}
```
控制台输出:  
```c
before: 0x7ffe45e0c65e; after: 0x7ffe45e0c65f
0x7ffe45e0c65e 0x7ffe45e0c660
before: 0x7ffe45e0c672; after: 0x7ffe45e0c673
0x7ffe45e0c672 0x7ffe45e0c674
0x7ffde6af99d6 0x7ffde6af99d7
```
**猜想**:void*指针i自增为1?  

###从指针减去整数  
地址值会减去数据类型的长度和整数值的乘积  

```c
#define TYPE short

void print(TYPE * pv) {
    printf("before: %p; after: %p\n", pv, pv-1);
}

//指针算术
void testPointer() {
    TYPE t = 1;
    TYPE * p1 = &t;
    print(p1);
//    printf("%p %p\n", p1, p1+1);
    TYPE type[] = {1,2,3};
    TYPE * p2 = &type[0];
    print(p2);
//    printf("%p %p\n", p2, p2+1);
//    void * pv = p1;
//    printf("%p %p\n", pv,  pv+1);
}
```
控制台输出:  
```c
before: 0x7fffbc1be69e; after: 0x7fffbc1be69c
before: 0x7fffbc1be6b2; after: 0x7fffbc1be6b0
```

###指针相减  
一个指针减去另一个指针会得到两个地址的差值,是它们之间相差的"单位"数,符号取决于操作数顺序  

###比较指针  
使用标准比较操作符比较,判断数组元素相对顺序  

#指针常见用法  
##多层间接引用  

##常量指针  
###指向常量的指针  






