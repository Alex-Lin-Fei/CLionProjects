#include <iostream>
#include <vector>
using namespace std;

bool canWordBreak(string s, vector<string>& wordDict) {
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

vector<string> wordBreak(string s, vector<string>& wordDict) {
    if(!canWordBreak(s, wordDict))
        return {};
    vector<vector<string>> dp(s.length() + 1);
    dp[0].push_back("");
    for (int j = 1; j <= s.length(); j++)
        for (auto &word: wordDict)
            if (j >= word.length() && s.substr(j - word.length(), word.length()) == word) {
                for(auto x: dp[j-word.length()]) {
                    if (!x.empty())
                        x.append(" ");
                    dp[j].push_back(x.append(word));
                }
            }
    for(auto& v: dp){
        for(auto& x: v)
            cout <<x <<endl;
    }
    cout <<"ans:\n";
    for(auto& x: dp[s.length()])
        cout << x<<endl;
    return dp[s.length()];
}

int main() {
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
    wordBreak("catsanddog", wordDict);
    return 0;
}
