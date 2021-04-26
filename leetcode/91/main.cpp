#include <iostream>
#include <vector>
using namespace std;

int numDecodings(string s) {
    if(s.empty())
        return 0;
    int pre = s[0] - '0';
    if(pre == 0)
        return 0;
    if(s.length() == 1)
        return 1;
    vector<int> dp(s.length() + 1, 1);
    for (int i = 2; i <= s.length(); i++) {
        int cur = s[i - 1] - '0';
        if ((pre == 0 || pre > 2) && cur == 0)
            return 0;
        if (pre > 0 && pre < 2 || cur < 7 && pre == 2) {
            if (!cur)
                dp[i] = dp[i - 2];
            else
                dp[i] = dp[i - 2] + dp[i - 1];
        } else
            dp[i] = dp[i - 1];
        pre = cur;
    }
    return dp.back();
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
