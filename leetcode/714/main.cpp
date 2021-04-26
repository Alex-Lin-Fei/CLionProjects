#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    vector<int> dp(2);

    dp[0] = 0;
    dp[1] = -prices[0] - fee;

    for (int i = 1; i < prices.size(); i++) {
        dp[0] = max(dp[1] + prices[i], dp[0]);
        dp[1] = max(dp[1], dp[0] - prices[i] - fee);
    }
    return dp[0];
}

int main() {
    vector<int> prices{1,3,2,8,4,9};
    priority_queue<int> que;
    que.push(1);
    que.push(4);
    que.push(2);
    while(!que.empty()) {
        cout << que.top() << endl;
        que.pop();
    }
    std::cout << maxProfit(prices, 2) << std::endl;

    return 0;
}
