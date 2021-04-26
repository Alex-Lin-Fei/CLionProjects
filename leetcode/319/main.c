#include <stdio.h>

int bulbSwitch(int n) {
    int ans = 1;
    while (ans * ans <= n)
        ans++;
    return ans-1;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
