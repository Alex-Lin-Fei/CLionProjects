#include <stdio.h>
double nthPersonGetsNthSeat(int n) {
    return n == 1 ? 1 : 0.5;
}

int main() {
    printf("%f\n", nthPersonGetsNthSeat(3));
    return 0;
}
