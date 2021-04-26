#include <iostream>
#include <vector>
using namespace std;

//    保存列位
vector<int> row;
//    当前列 对角线标记
vector<bool> leftDiag, rightDiag, cols;
int ans;

void Nex(int cur, int n) {
    if (cur == n)
        ans++;
    else
        for (int c = 0; c < n; c++) {
            if (leftDiag[cur - c + n - 1] && rightDiag[c + cur] && cols[c]) {
                leftDiag[cur - c + n -1] = rightDiag[c + cur] = cols[c] = false;
                row[cur] = c;
                Nex(cur + 1, n);
                leftDiag[cur - c + n-1] = rightDiag[c + cur] = cols[c] = true;
                row[cur]=-1;
            }
        }
}

int totalNQueens(int n) {
    row.clear();
    leftDiag.clear();
    rightDiag.clear();
    cols.clear();

    row.resize(n, -1);
    cols.resize(n, true);
    leftDiag.resize(2*n-1, true);
    rightDiag.resize(2*n-1, true);

    Nex(0, n);

    return ans;
}



int main() {
    std::cout << totalNQueens(4) << std::endl;
    return 0;
}
