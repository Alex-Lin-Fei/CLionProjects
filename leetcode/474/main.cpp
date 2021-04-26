#include <iostream>
#include <vector>
using namespace std;

pair<int, int> count(string & s) {
    int zeros = s.length();
    int ones = 0;
    for (auto &ch: s)
        if (ch == '1') {
            ones++;
            zeros--;
        }
    return {zeros, ones};
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (auto &str: strs) {
        pair<int, int> temp = count(str);
        for (int i = m; i >= temp.first; i--)
            for (int j = n; j >= temp.second; j--)
                dp[i][j] = max(dp[i][j], dp[i - temp.first][j - temp.second] + 1);
    }
    return dp[m][n];
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
