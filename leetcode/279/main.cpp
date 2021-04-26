#include <iostream>
#include <vector>
using namespace std;

int numSquares(int n) {
    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    return dp[n];
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
