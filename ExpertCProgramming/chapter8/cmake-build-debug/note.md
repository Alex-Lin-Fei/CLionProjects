#在等待时类型发生了变化  
在表达式中,每个char和short都被转换为int,所有float都被转换为double,由于函数参数也是一个表达式,参数传递时也会发生类型转换  
示例代码:  
```c
    printf("%d\n", sizeof 'a');
//console
4
```
这个特性称为类型提升  
整型提升就是char, short, int和位段类型(无论signed或unsigned)以及枚举类型将被提升为int,前提是int能够完整地容纳原先的数据,否则将被转换为unsigned int


K＆R C的函数定义：
```c
function()
char c;
short si;
float f;
{
....
}
```

这种方式定义的函数，其参数在使用时，会先按被隐式类型转换之后的大小，从堆栈中提取出来，然后再按函数定义中的实际类型进行截取。如，char类型变量c实际访问时，先在堆栈中变量c的存储位置，提取出一个int大小的“临时变量”，然后将该“临时变量”截取成一个char变量再进行运算。short及float变量同理。

ANSI C的函数定义：
```c
int function( char c, short si, float f )
{
....
}
```

这种方式定义的函数，其参数使用时，直接从堆栈中按实际定义的大小进行提取即可。
故K＆R C和ANSI C的函数声明及定义，在参数类型转换上的区别可分为两个部分：
1. 在参数传递给该函数时，是否发生了类型提升？K＆R C有类型提升，ANSI C没有
2. 在函数实际使用其参数时，是否发生了字节截取？K＆R C有，而ANSI C没有
