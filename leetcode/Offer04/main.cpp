#include <iostream>
#include <vector>
using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() || matrix[0].empty())
        return false;
    int i = 0, j = matrix[0].size()-1;

    while(i >= 0 && i < matrix.size() && j < matrix[0].size() && j >= 0) {
//        cout << matrix[i][j] << endl;
        if (matrix[i][j] > target)
            j--;
        else if (matrix[i][j] < target)
            i++;
        else
            return true;
    }
    return false;
}

bool SearchMatrix(vector<vector<int>>& matrix, int target, int minX, int maxX, int minY, int maxY) {
    if (minX <= maxX && minY <= maxY) {
        int x = (minX + maxX)  /2;
        int y = (minY + maxY) /2 ;

        if (matrix[x][y] == target)
            return true;
        else if (matrix[x][y] < target)
            return SearchMatrix(matrix, target, x + 1, maxX, minY, y) ||
                   SearchMatrix(matrix, target, minX, maxX, y + 1, maxY);
        else
            return SearchMatrix(matrix, target, minX, maxX, minY, y - 1) ||
                   SearchMatrix(matrix, target, minX, x - 1, y, maxY);
    } else
        return false;
}


int main() {
    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24},
                                  {18,21,23,26,30}};
    cout << SearchMatrix(matrix, 19, 0, matrix.size()-1, 0, matrix[0].size()-1)<<endl;
    for(auto& r: matrix)
    for(auto& num: r)
    std::cout << num << ": " << SearchMatrix(matrix, num, 0, matrix.size()-1, 0, matrix[0].size()-1) << std::endl;
    return 0;
}
