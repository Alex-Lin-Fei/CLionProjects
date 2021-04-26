#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<int> dir{-1, 0, 1, 0, -1};
vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    queue<tuple<int, int>> que;
    vector<vector<int>> ans;
    vector<vector<int>> visited(R, vector<int>(C));

    que.push(tuple<int, int>(r0, c0));
    visited[r0][c0] = true;
    while (!que.empty()) {
        tuple<int, int> t = que.front();
        que.pop();
        int x = get<0>(t);
        int y = get<1>(t);

        ans.push_back(vector<int>{x, y});

        for (int i = 0; i < 4; i++) {
            int a = x + dir[i];
            int b = y + dir[i + 1];
            if (a < R && a >= 0 && b < C && b >= 0 && !visited[a][b]) {
                visited[a][b] = true;
                que.push(tuple<int, int>(a, b));
            }
        }
    }
    for(auto& v: ans)
        cout << v[0] << ' ' << v[1]<<endl;
    return ans;
}

int main() {
    allCellsDistOrder(2,3,1,2);
    return 0;
}
