#include <iostream>
#include <vector>
using namespace std;

int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1));
    for (int i = 0; i <= word1.length(); i++)
        dp[i][0] = i;
    for (int i = 0; i <= word2.length(); i++)
        dp[0][i] = i;
    for (int i = 1; i <= word1.length(); i++)
        for (int j = 1; j <= word2.length(); j++) {
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 1,
                           dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 2));
        }
    return dp[word1.length()][word2.length()];
}


int main() {

    std::cout << "Hello, World!" << std::endl;
    return 0;
}