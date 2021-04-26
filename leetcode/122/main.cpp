#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    vector<int> sell(prices.size());
    vector<int> buy(prices.size());
    sell[0] = 0;
    buy[0] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
    }
    return sell.back();
}

int main() {
    vector<int> p{7,6,4,3,1};
    std::cout << maxProfit(p) << std::endl;
    return 0;
}
