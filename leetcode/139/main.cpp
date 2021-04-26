#include <iostream>
#include <vector>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.length() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.length(); i++) {
        for (auto &str: wordDict) {
            int len = str.length();
            if (i >= len && s.substr(i - len, len) == str)
                dp[i] = dp[i] | dp[i - len];
        }
    }
    return dp.back();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
