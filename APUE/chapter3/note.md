#文件IO  
##引言  
unix系统中大多数文件io只需用到五个函数：open，read，write，lseek，close  
本章描述的函数经常被称为**不带缓冲**的io。术语**不带缓冲**指的是每个read和write都调用内核中的一个系统调用。这些不带缓冲的io函数不是iso c的组成部分  

##文件描述符  
