#include <iostream>

int main() {
    int x;
    scanf("%d", &x);
    int t[x];

    std::cout << sizeof t / sizeof(int) << std::endl;
    return 0;
}
