#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;


int shortestSubarray(vector<int>& A, int K) {
    deque<int> que;

    vector<int> preSum(A.size() + 1);
    int ans = A.size() + 1;
    for (int i = 1; i <= A.size(); i++)
        preSum[i] = preSum[i - 1] + A[i - 1];

    int p = 0;
    for (int i = 0; i < preSum.size(); i++) {
        while (!que.empty() && preSum[que.back()] >= preSum[i])
            que.pop_back();
        while (!que.empty() && preSum[i] >= K + preSum[que.front()]) {
            ans = min(ans, i - que.front());
            que.pop_front();
        }
        que.push_back(i);
    }
    return ans;
}


int main() {
    long r = 2;
    int x = -1;
    if(x < r)
        cout <<"888";
    vector<int> A{56,-21,56,35,-9};
    std::cout << shortestSubarray(A, 61) << std::endl;
    return 0;
}
