#include <stdio.h>
#include <string.h>

char * strrstr(const char * s1, const char * s2) {
    register char * last;
    register char * current;
    last = NULL;
    if (*s1 != '\0') {
        current = strstr(s1, s2);
        while (current != NULL) {
            last = current;
            current = strstr(last+1, s2);
        }
    }
    return last;
}

char * strrpbrk(const char * str, const char * group) {
    register char * last;
    register char * current;
    last = NULL;
    if (*str != '\0') {
        current = strpbrk(str, group);
        while (current != NULL) {
            last = current;
            current = strpbrk(last+1, group);
        }
    }
    return last;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
