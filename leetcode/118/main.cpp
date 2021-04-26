#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows == 0)
        return ans;
    ans.push_back({1});

//    每一行
    for (int i = 2; i <= numRows; i++) {
        vector<int> row;
        row.push_back(1);
//        每个元素
        for (int j = 1; j < i - 1; j++)
            row.push_back(ans.back()[j - 1] + ans.back()[j]);
        row.push_back(1);
        ans.push_back(row);
    }

    return ans;
}

int main() {
    vector<vector<int>> ans;

    ans = generate(1);
    for (auto& row:ans) {
        for (auto &i: row)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}
