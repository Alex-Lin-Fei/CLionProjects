#include <iostream>
#include <vector>
using namespace std;


vector<vector<string>> ans; //存储每一个正确答案

vector<int> row; //保存答案
vector<bool> col;//列正确
vector<bool> leftDiag; //左对角线正确
vector<bool> rightDiag; //右对角线正确

void Backtrack(int cur, int &N) {
    if (cur == N) {
        vector<string> tmp;
        for (int i = 0; i < N; i++) {
            string stri;
            int j = 0;
            while (j < N) {
                stri += (j == row[i] ? 'Q' : '.');
                j++;
            }

            tmp.push_back(stri);
        }
        ans.push_back(tmp);
    } else {
        for (int i = 0; i < N; i++) {
            if (col[i] && leftDiag[cur-i+N-1] && rightDiag[cur+i])
            {
                col[i] = leftDiag[cur-i+N-1] = rightDiag[cur+i] = false;
                int t = row[cur];
                row[cur] = i;
                Backtrack(cur+1, N);
                col[i] = leftDiag[cur-i+N-1] = rightDiag[cur+i] = true;
                row[cur] = t;
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
//    init
    col.resize(n, true);
    leftDiag.resize(n*2-1, true);
    rightDiag.resize(n*2-1, true);
    row.resize(n, -1);
    ans.clear();

    Backtrack(0, n);
    for(auto& v: ans) {
        for (auto &s: v)
            cout << s << endl;
        cout << endl;
    }
    return ans;
}

int main() {
    solveNQueens(4);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
