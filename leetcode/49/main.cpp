#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    map<string, vector<string>> record;

    for (auto str: strs) {
        string temp = str;
        sort(str.begin(), str.end());
        record[str].push_back(temp);
    }

    ans.reserve(record.size());
    for (auto &iter: record)
        ans.push_back(iter.second);

    for(auto& v: ans) {
        for (auto &s: v)
            cout << s << " ";
        cout << endl;
    }

    return ans;
}

int main() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(strs);
    return 0;
}
