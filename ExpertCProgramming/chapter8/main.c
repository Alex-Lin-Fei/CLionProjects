#include <stdio.h>

int func(int x) {
    printf("%d\n", sizeof x);
}

int main() {
    long long x = 98;
    printf("%d %d\n", sizeof 'a', x);
    return 0;
}
