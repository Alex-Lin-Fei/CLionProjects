#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
//    vector<int> dp(A.size(), 0);
//    for (int i = 2; i < A.size(); i++)
//        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
//            dp[i] = dp[i - 1] + 1;
//    return accumulate(dp.begin(), dp.end(), 0);
    int s = 0;
    int temp = 0;
    for (int i = 2; i < A.size(); i++)
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            s += temp;
            temp += 1;
        } else
            temp = 0;

    return temp + s;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
