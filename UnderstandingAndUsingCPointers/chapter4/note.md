#指针和数组  
尽管数组名字有时候可以当做指针来用，但数组名字不是指针  

##数组概述  
数组是能用索引访问的同质元素连续集合．这里连续指的是数组元素在内存中是相邻的，同质指的是数组元素是同一类型的  

##一维数组  
示例代码:  
```c
int vector[5];
printf("%d\n", sizeof vector / sizeof(int));
```
对数组名做sizeof操作会得到为该数组分配的字节数  

##二维/多维数组  
见page77  

##指针表示法和数组  
可以用指针指向已有的数组，也可以从堆上分配内存然后把这块内存当作一个数组使用  

单独使用数组名时会返回数组地址  
```c
    int * pv = vector;
```
pv变量指向的是第一个元素而不是数组本身．可以使用数组名字，也可以对数组的第一个元素取地址操作符  
有时候也会使用&vector获取数组地址，这么做是返回整个数组的地址，其他两种方法是获取整数的指针
示例代码
```c
 printf("&vector: %p; vector: %p; &vector[0]: %p\n", &vector, vector, &vector[0]);
    printf("&vector: %p; vector: %p; &vector[0]: %p\n", &vector+1, vector+1, &vector[0]+1);
```
运行结果:  
```c
&vector: 0x7ffcd995c970; vector: 0x7ffcd995c970; &vector[0]: 0x7ffcd995c970
&vector: 0x7ffcd995c984; vector: 0x7ffcd995c974; &vector[0]: 0x7ffcd995c974
```
可见，&vector+1比&vector多了整个数组的长度，而其他两个则是多了一个int长度  

###数组和指针的差别  
vecotor[i]和*(vector+i)的生成代码不同  
+ vector[i]: 从位置vector开始，移动i个位置，取出内容
+ *(vector+i):从vector开始在地址上增加i个长度然后取出该地址中的内容  

sizeof操作符对数组和同一数组的指针也是不同的．对vector调用sizeof会返回20,就是分配的字节数目,而对pv调用则返回指针长度  
pv是一个左值，可以被修改，而数组是一个右值，不能被修改,我们不能改变数组持有的地址  

##传递一维数组  
将一维数组作为参数传递给函数实际上是通过值来传递数组的地址，并且需要长度信息  
###数组表示法  
示例代码:  
```c
void displayArray(int arr[], int size) {
    printf("arr size: %d\n", sizeof arr);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```
**note: 为确定数组的元素大小而对数组使用sizeof 操作符是错误的**  

###指针表示法  
上述也可以使用int * arr 代替int arr[], *(arr+i)代替arr[i]  

###使用指针的一维数组  
```c
void displayPointer(int * * arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr+i) = (int*)malloc(sizeof(int));
printf("%p ", arr[i]);
**(arr+i) = i;
    }
}
```  
运行结果
```c
0x5586ff10c670 0x5586ff10c690 0x5586ff10c6b0 0x5586ff10c6d0 0x5586ff10c6f0
0 1 2 3 4
```  
但是arr[i]对应的分配内存的大小至少是指定的大小,可能还有一些保存控制信息的内存  


##动态分配二维数组  

###分配可能不连续的内存  
首先分配连续内存,然后是各行所需内存  
示例代码
```c
 int rows = 3;
    int columns = 5;

    int ** matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(columns*sizeof (int));
        printf("%p  ", matrix[i]);
    }
```
运行结果: 
```c
0x5556a5459280  0x5556a54596b0  0x5556a54596d0
```
因为分别使用了malloc函数,实际的分配情况取决于堆管理器和堆的状态,也有可能是连续的  

###分配连续内存  
一次性分配所有内存  
```c


void test2() {
    int rows = 3;
    int columns = 5;

    int ** matrix = (int**) malloc(rows * sizeof(int*));
    matrix[0] = (int *) malloc(rows * columns * sizeof(int));
    for (int i = 0; i < rows; i++) {
        matrix[i] = matrix[0] + i * columns * sizeof (int);
        printf("%p  ", matrix[i]);
    }
}
```
运行结果:  
```c
0x55a14eda8280  0x55a14eda82d0  0x55a14eda8320
```
各元素地址相差相同,因此是连续的  