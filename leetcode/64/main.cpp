#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector<int> dp(grid[0].size(), 0);
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++) {
            if (i == 0 && j == 0)
                dp[j] = grid[i][j];
            else if (i == 0)
                dp[j] = dp[j - 1] + grid[i][j];
            else if (j == 0)
                dp[j] = dp[j] + grid[i][j];
            else
                dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
        }
    return dp.back();
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
