#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), [](vector<int, int> a, vector<int, int> b) {
        return a[1] < b[1] || a[0] < b[0];
    });
    int maxL = 1;
    int end = pairs[0][1];
    for (int i = 1; i < pairs.size(); i++) {
        if (pairs[i][0] > end) {
            end = pairs[i][1];
            maxL++;
        }
    }
    return maxL;
}

int main() {

    return 0;
}
