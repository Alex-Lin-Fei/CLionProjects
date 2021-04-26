#include <iostream>
#include <vector>
using namespace std;

int integerBreak(int n) {
    vector<int> dp(n+1);
    for(int i = 1; i <= n;i++)
        for (int j = 1; j < i; j++) {
            int x = max(dp[j], j);
            int y = max(dp[i-j], i-j);
            dp[i] = max(x*y, dp[i]);
        }
    return dp[n];
}


int main() {
    std::cout << integerBreak(8) << std::endl;
    return 0;
}
