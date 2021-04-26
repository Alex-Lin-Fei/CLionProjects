#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(3));
    dp[0] = {-prices[0], 0, 0};
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
        dp[i][1] = dp[i - 1][0] + prices[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
    }
    return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
