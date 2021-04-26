#include <iostream>
#include <vector>
using namespace std;

//math
/*
int countNumbersWithUniqueDigits(int n) {
    if (n == 0)
        return 1;
    n = min(n, 10);
    int pre = 10;
    int nex = 9 * 9;
    for (int i = 2; i <= n; i++) {
        pre += nex;
        nex *= 10 - i;
    }
    return pre;
}
 */

int backtrack(int cur, int& n, vector<bool> used) {
    if (cur != n) {

    }
}

int countNumbersWithUniqueDigits(int n) {
    vector<bool> used(10);

}


int main() {
    std::cout << countNumbersWithUniqueDigits(3) << std::endl;
    return 0;
}
