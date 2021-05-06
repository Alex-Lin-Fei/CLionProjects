#include <stdio.h>

char s[4];
char* foo() {
//    s[0]='a';
    static char s[] = "abc";

    return s;
}

int main() {
    int N = 10;
    int * q = &N;
    int p = N * sizeof * q;
    int apple = sizeof(int) * p;

    printf("p : %d; apple: %d; int: %lu\n", p, apple, sizeof(int));
    int x = (1, N);
    printf("x: %d\n", x);
    printf("%s", foo());

    return 0;
}
