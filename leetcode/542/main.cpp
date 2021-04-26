#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//动态规划

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int>(n, INT32_MAX - 1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0)
                dp[i][j] = 0;
            else {
                if (i > 0)
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);
                if (j > 0)
                    dp[i][j] = min(dp[i][j - 1] + 1, dp[i][j]);
            }
        }
    }
    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 0)
                dp[i][j] = 0;
            else {
                if (i < m - 1)
                    dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j]);
                if (j < n - 1)
                    dp[i][j] = min(dp[i][j + 1] + 1, dp[i][j]);
            }
        }
    for (auto &row: dp) {
        for (auto &i: row)
            cout << i << ' ';
        cout << endl;
    }
    return dp;
}


//广度优先搜索
/*
vector<int> dir{-1, 0, 1, 0, -1};
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1));

//    初始化队列 将为0的位置加入队列
    queue<pair<int, int>> que;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                que.push({i, j});
                ans[i][j] = 0;
            }
        }
    //    层次遍历
    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

//        枚举相邻的位置
        for (int k = 0; k < 4; k++) {
            int a = x + dir[k];
            int b = y + dir[k + 1];
            if (a >= 0 && a < m && b >= 0 && b < n && ans[a][b] == -1) {
                ans[a][b] = ans[x][y] + 1;
                que.push({a, b});
            }
        }
    }
    for (auto &row: ans) {
        for (auto &i: row)
            cout << i << ' ';
        cout << endl;
    }
    return ans;
}
*/

int main() {
    vector<vector<int>> matrix{{0, 0, 0},
                               {0, 1,1},
                               {1,1,1}};
    updateMatrix(matrix);
    return 0;
}
