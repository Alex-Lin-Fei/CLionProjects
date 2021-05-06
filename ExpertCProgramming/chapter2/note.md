##sizeof  
是一个操作符而不是函数，当操作的是类型时需要加括号  
```c
int * p = ..;
sizeof *p;
sizeof(int);  
```
##解决局部变量被销毁的问题  
bad code  
```c
char * foo() {
    char s[] = "abc";
    return s;
}

//console
(null)
```
buffer是一个自动分配内存的数组，是该函数的局部变量，当函数结束时，该变量  
已经被销毁，所占用内存被回收  
+ 返回一个指向字符串常量的指针  
```c
char * foo() {
    char * s = "abc";
    return s;
}
```

+ 使用全局声明的数组  
```c

char s[4];
char* foo() {
    s[0]='a'; 
//    char s[] = "abc";

    return s;
}

```

+ 使用静态数组  
```c
char* foo() {
    static char s[] = "abc";
//    char s[] = "abc";

    return s;
}

```
静态变量的使用参考书籍  
+ 显式分配内存
```c
char* foo() {
    char * s = malloc(120);
...
return s;
}

```
每次调用均创建一个新的缓冲区，适用于多线程代码  
+ 调用者自行分配内存保存返回值  
```c
void foo(char * res, int size) {
    strncpy(res, "...", size);
}

buffer = malloc(size);
foo(buffer, size);
....
free(buffer);
```


