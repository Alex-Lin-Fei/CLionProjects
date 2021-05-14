#体验Cache  
运行如下示例代码,检测cache效果  
```c

#define DUMBCOPY for (i = 0; i < 65536; i++) destination[i] = source[i]

#define SMARTCOPY memcpy(destination, source, 65536)

int main() {
    char source[65536], destination[65536];
    int i, j;
    for (j = 0; j < 100; j++)
        DUMBCOPY;
//        SMARTCOPY;

    return 0;
}

```
使用SMARTCOPY,终端输出:  
```c
cc -O main.c
time a.lout
a.out  0.00s user 0.00s system 85% cpu 0.003 total
```
使用DUMPCOPY,终端输出  
```c
cc -O main.c
time a.lout
a.out  0.00s user 0.00s system 95% cpu 0.007 total
```
#数据段和堆  
堆区域用于动态分配的存储,也就是通过malloc(内存分配)函数获得内存,并通过指针访问,堆中所有东西都是匿名的,不能按照名字直接访问,只能通过指针  
从堆中获取内存的唯一方法就是调用malloc(以及同类的calloc, realloc等)库函数.calloc函数与malloc类似,但它返回指针之前先把分配好的内存的内容都清空为0  
realloc函数改变一个指针所指内存块大小,既可以将其扩大,也可以把它缩小,经常把内存拷贝到其他地方然后将指向新地址的指针返回  
堆内存的回收不必按照它所分配的顺序一致,所以最终会产生堆碎片,被分配的内存总是经过对齐,以适合机器上最大尺寸的原子访问  

#内存泄漏  
堆经常会出现两种类型的问题:  
+ 释放或改写仍在使用的内存--内存损坏  
+ 未释放不再使用的内存--内存泄漏 

避免内存泄漏:每次调用malloc分配内存时,注意以后调用free方法释放,或者使用alloca来分配内存,当离开调用alloca函数的函数时,它所分配的内存会被自动释放  

#总线错误  
bus error -- 总线错误  
segmentation fault -- 段错误  

事实上,总线错误几乎都是由于未对齐的读或写引起的,之所以称为总线错误,是因为出现未对齐的内存访问请求时,被阻塞的组件就是地址总线.对齐的意思就是数据项只能存储在地址是数据项大小的整数倍的内存地址上  

段错误或违规(segmentation violation)是由于内存管理单元的异常引起的,而该异常通常是由于解除引用一个未初始化或非法值的指针引起的  
如果未初始化的指针恰好具有未对齐的值,会产生一个总线错误而不是段错误,因为绝大多数架构的计算机,cpu先看到地址再把它给mmu  
示例代码:  
```c
union {
    char a[10];
    int i;
}u;

void test() {
   int *p = (int *)&(u.a[1]);
   *p = 17;
    printf("p: %p; *p: %d\n", p, *p);

    int *q = 0xddc53018;
    *q = 18;
}
//console
p: 0x55fc91320019; *p: 17

Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)
```
并未出现总线错误,出现了段错误    
原因是：
x86体系结构会把地址对齐之后，访问两次，然后把第一次的尾巴和第二次的头拼起来。
如果不是x86，那种体系结构下的机器不肯自动干这活，就会产生core。
如果在代码中将对齐检查功能打开，运行后能显示bus error


