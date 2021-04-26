#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool wordPattern(string pattern, string s) {
    map<string, char> StrToCh;
    map<char, string> ChToStr;

    // 提取取单词
    vector<string> words;
    int idx = 0;
    string str;
    while (idx < s.length()) {
        if (s[idx] != ' ')
            str += s[idx];
        else {
            words.push_back(str);
            str = "";
        }
        idx++;
    }
    if (str.length() != 0)
        words.push_back(str);
    if (words.size() != pattern.length())
        return false;
    for (int i = 0; i < words.size(); i++) {
        if (ChToStr.count(pattern[i]) && ChToStr[pattern[i]] != words[i])
            return false;
        else if (StrToCh.count(words[i]) && StrToCh[words[i]] != pattern[i])
            return false;
        StrToCh[words[i]] = pattern[i];
        ChToStr[pattern[i]] = words[i];
    }

    return true;
}

int main() {
    map<int, string> m;
    cout << wordPattern("aad", "cat cat cat");

    return 0;
}
