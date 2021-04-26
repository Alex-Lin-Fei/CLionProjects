#include <iostream>
#include <map>
using namespace std;

string sortString(string s) {
    map<char, int> count;
    bool flag = true;
    string ans;
    for (auto &ch: s)
        count[ch]++;
    for (auto &item: count)
        cout << item.first << ' ' << item.second << endl;
    while (flag) {
        flag = false;
//        正序
        for (auto & item: count) {
            if (item.second)
            {
                ans += item.first;
                item.second--;
                flag = true;
            }
        }
//        反序
        for (auto item = count.rbegin(); item  != count.rend(); item++) {
            if ((*item).second) {
                ans += (*item).first;
                item->second--;
                flag = true;
            }
        }
    }
    cout << ans;
    return ans;
}

int main() {
    sortString("leetcode");
    return 0;
}
