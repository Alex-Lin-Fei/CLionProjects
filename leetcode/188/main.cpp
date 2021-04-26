#include <iostream>
#include <vector>
using namespace std;

int maxProfitUnlimited(vector<int>& prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1])
            ans += prices[i] - prices[i - 1];
    }
    return ans;
}

int maxProfit(int k, vector<int>& prices) {
    if (k >= prices.size()/2)
        return maxProfitUnlimited(prices);
    vector<int> buy(k + 1, INT32_MIN);
    vector<int> sell(k + 1, 0);
        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = max(sell[i - 1] - price, buy[i]);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }

    for(int i = 1; i <= k; i++)
        cout << buy[i]<<' '<<sell[i]<<endl;
    return sell.back();
}

int main() {
    vector<int> prices{3,2,6,5,0,3};
    std::cout << maxProfit(2, prices) << std::endl;
    return 0;
}
