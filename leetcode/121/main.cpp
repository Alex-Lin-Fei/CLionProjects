#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int sell = 0, buy = INT32_MIN;

    for (int price : prices) {
        buy = max(buy, -price);
        sell = max(sell, buy + price);
    }
    return sell;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
