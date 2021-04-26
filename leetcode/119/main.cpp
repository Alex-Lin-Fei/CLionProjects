#include <iostream>
#include <vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> ans, pre;
    pre.push_back({1});
    if (rowIndex == 0)
        return pre;

//    每一行
    for (int i = 1; i <= rowIndex; i++) {
        ans.push_back(1);
//        每个元素
        for (int j = 1; j < i; j++)
            ans.push_back(pre[j - 1] + pre[j]);
        ans.push_back(1);
        pre = ans;
        ans.clear();
    }
    return pre;
}


int main() {
    vector<int> v = getRow(4);
    for(auto& i: v)
        cout <<i<<' ';
    return 0;
}
