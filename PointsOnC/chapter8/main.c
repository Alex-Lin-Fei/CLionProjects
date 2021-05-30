#include <stdio.h>

int main() {
    char * p  = "Hello";
    char t[] = "Hello";
    printf("%p %p %p\n", p, &t, "Hello");
    return 0;
}
