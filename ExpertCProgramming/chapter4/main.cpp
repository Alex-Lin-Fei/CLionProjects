#include <iostream>

int main() {
    int x = 12;
    float y = x;
    printf("x: %s %d\n", typeid(x).name(), x);
    printf("y: %s %f\n", typeid(y).name(), y);

    y = 12.0;
    x = y;
    printf("x: %s %d\n", typeid(x).name(), x);
    printf("y: %s %f", typeid(y).name(), y);
    return 0;
}

