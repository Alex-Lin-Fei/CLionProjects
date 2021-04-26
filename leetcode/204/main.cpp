#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    if (n < 2)
        return 0;

    vector<bool> isPrime(n + 1, true);
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            sum++;
            for (int j = i * 2; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return sum;
}

int main() {
    std::cout << countPrimes(12) << std::endl;
    return 0;
}
