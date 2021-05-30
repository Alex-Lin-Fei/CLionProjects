#函数  
##函数定义
语法:  
类型 函数名(形式参数) 代码块  
return语句允许从函数体的任何位置返回,并不一定要在函数体的末尾
##函数声明  
###原型
向编译器提供一些关于函数的的特定信息显然更为安全  
+ 如果源文件的前面已经出现了该函数的定义,编译器就会记住它的参数数量和类型,以及函数的返回值类型  
+ 使用函数原型,最方便且安全的方法就是将函数置于一个单独的文件,使用#include指令包含  

##函数的参数  
c函数所有参数均以"传值调用"方式进行传递,意味着函数将获得数值的一份拷贝.数组参数的行为称为传址调用,数组名实际上是一个指针  

##adt和黑盒  
c可以用于设计和实现抽象数据类型(adt, abstract data type),因为他可以限制函数和数据的定义和作用域  

##可变参数列表  