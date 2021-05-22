#include <stdio.h>

void test(char *s) {
    s[2] = 'x';
}

int main() {
    char s[] = "abc";
    test(s);
    printf("%s\n", s);
    return 0;
}
