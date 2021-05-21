#指针和函数

##程序的堆和栈  
**note**: 局部变量也称为自动变量,总是分配在栈帧上  
###程序栈  
程序栈是支持函数执行的内存区域,通常和堆共享.程序栈存放栈帧(stack frame),有时也称为活跃记录或者活跃帧.  
栈帧存放函数参数和局部变量  
调用函数时,函数的栈帧被推到栈上,栈向上长出一个栈帧,函数中止时,其栈帧从程序栈弹出,栈帧所使用的内存不会被清理,但可能被覆盖  
动态分配的内存来自堆,随着内村的分配和释放,堆中会布满碎片,实际上内存可能在堆上任意位置分配  

###栈帧的组织  
栈帧由以下几种元素组成:  
+ 返回地址  
  函数完成后要返回的程序内部地址
+ 局部数据存储   
  为局部变量分配的内存
+ 参数存储  
  为函数参数分配的内存  
+ 栈指针和基指针  
运行时系统用来管理栈的指针  
  
栈指针通常指向栈顶部,基指针(帧指针)通常存在并指向栈帧内部的地址,比如返回地址  
示例代码  
```c

float average(double  arr, int size) {
    int sum;

    printf("   arr: %p\n", &arr);
    printf(" size: %p\n", &size);
    printf(" sum: %p\n", &sum);
}

int main() {
//    int arr[] = {1,2,3};
double arr = 12;
    printf("%p\n", &arr);
    average(3, 3);
    double x;
    printf("%p\n", &x);
    average(4,4);


    return 0;
}
```
**运行结果与书本不同**: 
```c
0x7ffd1fdb0a28
   arr: 0x7ffd1fdb09e8
 size: 0x7ffd1fdb09e4
 sum: 0x7ffd1fdb09f4
0x7ffd1fdb0a30
   arr: 0x7ffd1fdb09e8
 size: 0x7ffd1fdb09e4
 sum: 0x7ffd1fdb09f4
```
书中提到：系统在创建栈帧时，将参数以跟声明时相反的顺序推到帧上，最后推入局部变量，而运行结果恰好相反．查看main函数中的两个变量地址，后声明的变量x地址比先声明的变量arr更高，但是都比average函数中的地址更高，可能单独一个函数内部入栈是从低地址往高地址压入．准备等到学完at&t汇编语言后查看main.c汇编结果    

##通过指针传递和返回数据　　
减少栈帧的占用内存，提高速度　　
###用指针传递数据　　
###传递指向常量的指针　　
不能修改通过指向常量的指针传入的值　　
```c

void passingAddressOfConstants(const int * num1, int *num2) {
    *num1 = *num2; //ERROR
}
```
###返回指针　　
+ 返回未初始化的指针
+ 返回指向无效地址的指针
+ 返回局部变量的指针
+ 返回指针但是没有释放内存　　

###局部数据指针　　
```c

int * allocateArray(int size, int value) {
    int arr[size];
//int * arr = (int*) malloc(sizeof(int)*3);
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
    return arr;
}
```
运行结果显示段错误　　

###传递指针的指针  
如果我们想修改原指针而不是指针的副本，需要传递指针的指针  
假如要实现自定义的free函数，free函数不会检查指针是否为NULL，也不会在返回前把指针置为NULL  
```c
void safeFree(void **pp) { //void*类型可传入所有类型指针
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}
```
可以使用一个宏调用函数，执行类型转换  
```c
#define safeFree(p) safeFree((void**)&(p))
```

##函数指针  
##声明函数指针　　
```c
void (*foo)();
```
示例代码:  
```c

int (*fptr)(int);

int square(int num) {
    return num * num;
}

void testFptr() {
    int n = 5;
    fptr = square;
    printf("%d squared is %d\n", n, fptr(n));
}
```
###函数指针数组　　
```c
int (*fptr[10])(int, int);
```

###比较函数指针  
可以通过==来比较两个函数指针是否相同  
##转换函数指针　　
慎用