#include <iostream>
#include <vector>
using namespace std;

int dir[] = {1, 0, -1, 0, 1};
int dfs(int x, int y, vector<vector<int>>& grid) {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0)
        return 1;
    else if (grid[x][y] == 2)
        return 0;
    else {
        grid[x][y] = 2;
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            int a = x + dir[i];
            int b = y + dir[i + 1];
            ans += dfs(a, b, grid);
        }
        return ans;
    }
}

int islandPerimeter(vector<vector<int>>& grid) {
    int ans = 0;

    if(grid.empty() || grid[0].empty())
        return ans;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[i].size(); j++)
            if (grid[i][j] == 1)
                ans += dfs(i, j, grid);
    return ans;
}


int main() {
    vector<vector<int>> grid{{0,1,0,0},
    {1,1,1,0},
    {0,1,0,0},
    {1,1,0,0}};
    std::cout << islandPerimeter(grid) << std::endl;
    return 0;
}
