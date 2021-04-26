#include <iostream>
using namespace std;

double Pow(double x, long long n) {
    if (n == 0)
        return 1.0;
    else {
        double y = Pow(x, n / 2);
        return n & 1 ? y * y * x : y * y;
    }
}

double myPow(double x, int n) {
    long long N = n;
    return N >= 0.0 ? Pow(x, N) : 1.0 / Pow(x, -N);
}

int main() {
    std::cout << myPow(2.00000, -2147483648) << std::endl;
    return 0;
}
