#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    vector<int> AB, CD;
    int ans=0;

    for (int i : A)
        for(int j : B)
            AB.push_back(i + j);
        sort(AB.begin(), AB.end());

        for (int i: C)
            for (int j: D)
                CD.push_back(i+j);

        sort(CD.begin(), CD.end());

        for (auto & i: AB) {
            int s = lower_bound(CD.begin(), CD.end(), -i) - CD.begin();
            int t = upper_bound(CD.begin(), CD.end(), -i) - CD.begin();
            ans += t - s;
        }


    return ans;
}

int main() {
    vector<int> A{1,2}, B{-2,-1}, C{-1,2}, D{0,2};
    std::cout << fourSumCount(A, B, C, D) << std::endl;
    return 0;
}
