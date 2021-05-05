/*
#include <stdio.h>

int main() {

//    标识符
//    浮点数
    float a = 9.1f;
    float b = 9.f;
//   错误类型  后缀错误  数字错误 小数点
    float c = 9.ff;
    float d = 8.f3;
    float e = 3.01.2;


//     二进制
    int f = 0b01;
    int g = 0B1u;
    int h = 0b1l;
    int i = 0B1ul;

//  错误类型  后缀错误  数字越界错误
    int j = 0b1f;
    int k = 0b0lf;
    int l = 0b1fu;
    int m = 0Buf;
    int n = 0b11f;

//     八进制
    int o = 012;
    int p = 012lu;
    int q = 012l;
    int r = 0710ul;
    int s = 014f;
    int t = 032lf;
    int u = 012fu;

//     十六进制  字母越界
    int v = 0xfff;
    int w = 0xabclu;
    int x = 0xty;
    int y = 0x3lf;

//     科学计数法  e前面没有数字  指数符号重复 指数有符号没有数字
    float n0 = 1.2e-1;
    float n1 = 9.8e+2;
    float n3 = -9.6e-1;
    float n4 = -9.e-4;
    float n5 = 0e0;
    float n6 = 2.1e+ - 9;
    float n7 = 21.2e1 +;
    float n8 = 1.e;

//     0开头的小数
    float a0 = 0.1;
    float a1 = 0.1f;
    float a2 = 0.0l;
    float a3 = 0.0e-9;
    float a4 = 0.ul;
    float a5 = 0.lu;
    float a6 = .0e-9lu;


//     .开头的小数和科学计数法  后缀错误  只有一个小数点
    float b0 = .1;
    float b1 = .1f;
    float b2 = .0e-9l;
    float b3 = .1ul;
    float b4 = .e - 9;
    float b5 = .;


    printf("Hello, World!\n");
    return 0;
}
*/


#include <stdio.h>
#include <string.h>
/*
void function(char * );
int main() {
    char large_string[256];

    for (int i = 0; i < 255; i++) {
        large_string[i] = 'A';
    }
    function(large_string);
}

void function(char* str) {
    char buffer[16];
    strcpy(buffer, str);
}
 */

void function(int , int , int );
int main() {
//    int x = 0;
//    function(1,2,3);
//    x = 1;
//    printf("%d\n", x);
    int a[5] = {0};
    printf("%d\n", a[3]);
    3[a] = 1;
    printf("%d\n", a[3]);

    return 0;
}

void function(int a, int b, int c) {
    char buffer1[5];
    char buffer2[10];
    int * r;
    r = buffer1 + 12;
    (*r) += 8;
}