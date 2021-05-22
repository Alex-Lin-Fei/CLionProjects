#指针和字符串  
字符串可以分配在内存的不同区域,通常使用指针来支持字符串操作  
字符串通常以字符指针的形式传递给函数和从函数返回.可以用字符指针传递字符串,也可以使用字符常量的指针传递字符串,后者可以避免字符串被函数修改   
也可以从函数返回字符串,或者将这个字符串从外面传给函数并由函数修改,也可以在函数内部分配,还可以返回静态分配的字符串  

##字符串基础  
c有两种类型的字符串:  
+ 由char数据类型组成的序列
+ 由wchar_t数据类型组成的序列  

wchar_t数据类型用来表示宽字符,主要用来支持非拉丁字符集  
**字符串的长度是字符串中除了NUL字符之外的字符数**,NULL通常定义为((void*)0),而NUL是一个char,定义为\0  
**在c中,字符常量的类型是int**  
```c
    printf("%d %d\n", sizeof(char), sizeof 'a');
```
运行结果:  
```c
1 4
```

###字符串声明  
声明字符串的方式有三种:  
+ 字面量  用双引号引起来的字符序列,常用来初始化,位于字符串字面量池中  
+ 字符数组  需要一个额外空间保存NUL 
+ 字符指针  


###字符串字面量池  
定义字面量时通常将其分配在字面量池中,这个内存区域保存了字符串的字符序列,通常只有一个副本,通常认为字面量是不可变的,大部分编译器有关闭字面量池的选项  
字符串字面量一般分配在只读内存中,无论在哪里使用,是否全局静态都无关紧要  


###字符串初始化  
####初始化char数组  
```c
char header[] = "Media";
```
字面量在字符串字面量池中,初始化操作会把这些字符复制到数组中,以NUL结尾

**不能把字符串字面量的地址赋给数组名字**:
```c
char header[] ;
header = "media"; //ERROR
```  

####初始化char指针  
常见的方法是使用malloc和strcpy函数分配内存并将字面量复制到字符串中  
```c
char *header = (char*)malloc(strlen("Media") + 1);
strcpy(header, "Media");
```
"Media"位于字符串字面量池中,堆中存在一份拷贝  

**note**:
+ 注意算上终结符NUL  
+ 不能使用sizeof操作符,会返回数组和指针的长度而非字符串长度  

也可以直接将字符串字面量的地址赋给指针,不过这样不会有堆的副本  
```c
char*header = "Media";
```

**note**:  
试用字符字面量初始化char指针不会其作用,因为字符字面量是int类型,其实是尝试把整数赋给字符指针  
```c
char* header = '+'; //Invalid
```
正确的做法是:  
```c
header = (char*)malloc(2);
*header = '+';
*(header+1) = 0;
```

###从标准输入初始化字符串  
下面是一个错误例子,因为没有为指针分配内存:  
```c
char * command;
scanf("%s", command);
```

##标准字符操作  

##传递字符串  
###传递简单字符串  

##返回字符串  
函数返回字符串时,实际上是字符串的地址,可以返回以下三种对象之一的引用:  
+ 字面量  
+ 动态分配的内存  
+ 本地字符串变量  

###返回字面量的地址  
针对多个不同目的返回一个静态字符串的指针存在覆写问题  
```c
char * staticFormat(const char *name, size_t quantity, size_t weight) {
static char buffer[24];
sprintf(buffer, "Item: %s Quantity: %u Weight: %u", name, quantity, weight);
return buffer;
}
char *part1 = staticFormat("Axle", 25, 45);
    printf("part1: %s\n", part1);

    char * part2 = staticFormat("Piston", 55,5);
    printf("part1: %s\n", part1);
    printf("part2: %s\n", part2);
```
运行结果:  
```c
Item: Axle Quantity: 25 Weight: 45
Item: Piston Quantity: 55 Weight: 5
Item: Piston Quantity: 55 Weight: 5
```
###返回动态分配的地址  
函数调用者需要释放内存  
```c
char* func() {
    char * spaces = (char*) malloc(size);
    ...
    return spaces;
} 
int main() {
    char * tmp = func();
    ...
    free(tmp);
}
```

###返回局部字符串的地址  
如果内存被别的帧覆写就会损坏,应该避免使用  
```c
char * func() {
    char spaces[size];
    ...
    return spaces;
}
int main() {
    char * s = func();
    ...
}
```
##返回指针和字符串
示例代码:  
```c

```