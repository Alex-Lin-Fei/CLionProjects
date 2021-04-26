#include <iostream>
#include <vector>
using namespace std;
//迷宫大小
const int N = 4;
const int N2 = 16;
const int LIMIT = 100;

//迷宫结构体
struct Puzzle{
    int f[N2];
    int space;
    int MD;
};

//v
Puzzle in, state; // 输入的迷宫 用于处理的迷宫
int limit; //限制
int path[LIMIT]; //存储路径




//方向
vector<pair<int, int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<char> direct{'r', 'd', 'l', 'u'};
vector<vector<int>> MDT; //存储曼哈顿距离

//process
int getMD(Puzzle& pz) {
    int ans = 0;
    for (int i = 0; i < N2; i++) {
        if (pz.f[i] == N2)
            continue;
        ans += MDT[i][pz.f[i] - 1];
    }
    return ans;
}

bool isSolved(Puzzle& pz) {
    for (int i = 0; i < N2; i++)
        if (pz.f[i] != i + 1)
            return false;
    return true;
}

bool dfs(int depth, int prev) {
    if (state.MD == 0)
        return true;
    if (depth + state.MD > limit)
        return false;
    int sx = state.space / N;
    int sy = state.space % N;
    Puzzle tmp{};

    for (int i = 0; i < 4; i++) {
        int tx = sx + dir[i].first;
        int ty = sy + dir[i].second;

        if (tx < 0 || tx >= N || ty < 0 || ty >= N)
            continue;
        if (abs(prev - i)==2)
            continue;
        tmp = state;
        state.MD -= MDT[tx * N + ty][state.f[tx * N + ty] - 1];
        state.MD += MDT[sx * N + sy][state.f[tx * N + ty] - 1];
        swap(state.f[tx * N + ty], state.f[sx * N + sy]);
        state.space = tx * N + ty;
        if (dfs(depth + 1, i)) {
            path[depth] = i;
            return true;
        }
        state = tmp;
    }
    return false;
}


string iterative_deepening(Puzzle& in) {
    in.MD = getMD(in);

    for (limit = in.MD; limit < LIMIT; limit++) {
        state = in;
        if (dfs(0, -100)) {
            string ans;
            for (int i = 0; i < limit; i++)
                ans += direct[path[i]];
            return ans;
        }
    }
    return "unsolvable";
}




int main() {
    MDT.resize(N2, vector<int>(N2));
//    initialize
    for (int i = 0; i < N2; i++)
        for (int j = 0; j < N2; j++)
            MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);

    cout << "enter the puzzle:\n";
    for (int i = 0; i < N2; i++) {
        cin >> in.f[i];
        if (in.f[i] == 0) {
            in.space = i;
            in.f[i] = N2;
        }
    }
    string ans = iterative_deepening(in);
    cout << ans << endl;
    for(int i = 0; i < N2; i++) {
        cout << state.f[i]<<' ';
        if (i % 4 == 3)
            cout << endl;
    }

    return 0;
}
