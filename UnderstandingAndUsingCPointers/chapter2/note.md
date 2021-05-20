#C的动态内存管理  

#动态内存分配  
在c中分配动态内存的基本步骤有:  
+ 用malloc类的函数分配内存
+ 用这些内存支持应用程序
+ free函数释放内存

##内存泄漏  
如果不再使用已经分配的内存却没有将其释放就会发生内存泄漏,导致内存泄漏的情况可能如下  
+ 丢失内存地址  
  当pi又指向第二次分配的内存时,第一次分配的内存的地址就会丢失
  
 ```c
int * pi = (int *) malloc(sizeof(int));
*pi = 3;
...
pi = (int *) malloc(sizeof(int));
 ```
下面这个例子是为字符串分配内存,将其初始化,并逐个打印字符串:  
```c
char  *name = (char*) malloc(strlen("susan")+1);
strcpy(name, "Susan");
while(*name != 0) {
    printf("%c", *name);
    name++;
}
```
丢失了起始地址
+ 应该调用free函数却没有调用，也叫隐式内存泄漏.释放struct关键字创建的结构体可能发生泄漏，因为可能包含动态分配内存的指针　　


#动态内存分配函数　　
+ malloc　从堆上分配内存
+ realloc　在之前分配的内存块的基础上，将内存重新分配为更大或更小的部分　
+ calloc　从堆上分配内存并清零
+ free　将内存块返回堆　　
动态内存从堆上分配，至于一连串内存分配调用，系统不保证内存顺序和分配内存的连续性．分配的内存会根据指针的数据类型对齐，堆管理器返回的地址是最低字节的地址　　
  
**静态 全局指针和malloc**:  
静态变量与全局变量不能初始化为动态内存，因为它们在编译时就，但动态内存是运行时确定的，但是可以通过复制语句更改它们的值　　
```c

static int *a;
int *b;

int main() {
    if (a == NULL)
        printf("null a ");
    printf("%d\n", a);
    if (b == NULL)
    printf("null b ");
    printf("%d\n", b);
    a = (int*) malloc(sizeof(int));
    b = (int*) malloc(sizeof(int));
    printf("%p %p\n", a, b);
    return 0;
}
```
运行结果:   
```c
null a 0
null b 0
0x55deee39a670 0x55deee39a690
```
**在编译器看来,作为初始化操作符＝和作为赋值操作符＝不一样**　　
##使用calloc函数　　
calloc函数会在分配的同时清空内存(将内容置为二进制０)，原型:  
```c
void *calloc(size_t numElements, size_t elementSize);
```
calloc会根据两个参数的乘积分配内存，返回一个指向内存第一个字节的指针，如果不能分配内存，则返回NULL
```c
int * p = calloc(5, sizeof(int));
//等价于
int *pi = malloc(5 * sizeof(int));
memset(pi, 0, 5 * sizeof(int));
```
##使用realloc函数
##alloca函数与变长数组　　
在函数的栈帧上分配内存，函数返回后会自动释放内存，所以不应该使用free释放它，也不应该返回指向数组的指针
#free 函数　
指针参数指向由malloc函数分配的内存的地址,这块内存会被返回给堆,尽管指针仍然指向这块区域  
如果传递给free函数的参数是NULL,通常什么都不做  
#迷途指针
如果内存已经释放,而指针还在引用原始内存,称为迷途指针  
会导致:  
+ 如果访问内存,则行为不可预期
+ 如果内存不可访问,则是段错误
+ 潜在的安全隐患  
因此释放指针后将其置为NULL  


 