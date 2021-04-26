#include <iostream>
#include <vector>
using namespace std;

int longestMountain(vector<int>& A) {
    int idx = 0;
    int l = -1, r = -1;
    int ans = 0;
    while (idx < A.size()) {
        while (idx + 1 < A.size() && A[idx] >= A[idx + 1])
            idx++;

        int s = idx;
        while (idx + 1 < A.size() && A[idx] < A[idx + 1])
            idx++;
        if (idx + 1 == A.size())
            break;
        else if (A[idx] == A[idx + 1])
            continue;
        while (idx + 1 < A.size() && A[idx] > A[idx + 1])
            idx++;

        if(idx-s+1>ans) {
            ans = idx - s + 1;
            l = s;
            r = idx;
        }
    }
    cout << l <<" " <<r<<endl;
    return ans;
}

int main() {
    vector<int> a{8};
    cout << longestMountain(a);

    return 0;
}
