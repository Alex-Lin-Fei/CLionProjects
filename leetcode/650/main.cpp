#include <iostream>
#include <vector>
using namespace std;

int minSteps(int n) {
    vector<int> dp(n + 1, INT32_MAX);

    dp[1] = 0;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i % j==0)
                dp[i] = min(dp[i], dp[j] + i / j);
    return dp[n];
}


int main() {

    std::cout << minSteps(3) << std::endl;
    return 0;
}
