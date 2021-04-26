#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT32_MAX);

    dp[0] = 0;
    for (auto &coin: coins) {
        for (int i = 1; i <= amount; i++) {
            if (i >= coin)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    return dp[amount];
}


int main() {
    vector<int> coins{1,2,5};
    cout << coinChange(coins, 11);
    return 0;
}
