#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//Kruskal
/*
struct Edge{
    int s{}, t{};
    int w{};
    Edge()= default;
    Edge(int s_, int t_, int w_): s(s_), t(t_), w(w_) {}
    bool operator<(const Edge & edge) const {
        return w < edge.w;
    }
};

vector<int> height, father;

void init(int n) {
    father.clear();
    height.clear();
    father.resize(n);
    height.resize(n);
    for (int i = 0; i < n; i++)
        father[i] = i;
}

int findFather(int a) {
    if (a != father[a]) {
        father[a] = findFather(father[a]);
    }
    return father[a];
}

bool isSame(int a, int b) {
    return findFather(a) == findFather(b);
}

void unite(int a, int b) {
    a = findFather(a);
    b = findFather(b);
    if (height[a] < height[b]) {
        father[a] = b;
    } else {
        father[b] = a;
        if (height[a] == height[b])
            height[a]++;
    }
}

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    int ans=0;
    vector<Edge> edges(n * (n - 1) / 2);

    for(int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            int w = abs(points[i][0] - points[j][0]) + abs(points[i][1]-points[j][1]);
            edges.emplace_back(i, j, w);
        }

    sort(edges.begin(), edges.end());
        init(n);
        for(auto& edge: edges) {
            if (!isSame(edge.s, edge.t)) {
                unite(edge.s, edge.t);
                ans += edge.w;
            }
        }
        return ans;
}
*/
// Prim

int Prim(vector<vector<int>> & v) {
    vector<bool> visited(v.size());
    vector<int> dist(v.size(), INT32_MAX);

    int nex, minD;
    int ans = 0;

    dist[0] = 0;
//    visited[0] = true;

    while (true) {
        nex = -1, minD = INT32_MAX;
        for (int i = 0; i < v.size(); i++)
            if (!visited[i] && dist[i] < minD) {
                nex = i;
                minD = dist[i];
            }
        if (nex == -1)
            break;
        ans += minD;
        visited[nex] = true;

        for (int j = 0; j < v.size(); j++)
            if (!visited[j] && v[nex][j] < dist[j])
                dist[j] = v[nex][j];
    }

    return ans;
}

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<vector<int>> grid(points.size(), vector<int>(points.size()));

    for (int i = 0; i < points.size(); i++)
        for (int j = i + 1; j < points.size(); j++)
            grid[i][j] = grid[j][i] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    return Prim(grid);
}


int main() {
    vector<vector<int>> points {{-1000000,-1000000},{1000000,1000000}};
    cout << minCostConnectPoints(points);
    return 0;
}
