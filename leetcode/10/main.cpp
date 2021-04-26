#include <iostream>
#include <vector>
using namespace std;

bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1));

    dp[0][0] = true;
    for (int i = 2; i <= p.length(); i++)
        if (p[i - 1] == '*')
            dp[0][i] = dp[0][i - 2];
    for (int i = 1; i <= s.length(); i++)
        for (int j = 1; j <= p.length(); j++) {
            if (p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] != '*')
                dp[i][j] = dp[i - 1][j - 1] && s[i - 1] == p[j - 1];
            else if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
                dp[i][j] = dp[i][j - 2];
            else
                dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
        }
    return dp[s.length()][p.length()];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
