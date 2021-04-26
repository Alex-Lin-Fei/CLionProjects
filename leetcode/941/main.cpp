#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& A) {
    if (A.size() < 3)
        return false;

    int idx = 0;
    if (A[idx] < A[idx + 1]) {
        while (idx < A.size() - 1 && A[idx] < A[idx + 1])
            idx++;
        if (idx >= A.size() - 1 && A[idx] == A[idx + 1])
            return false;
        while (idx < A.size() - 1 && A[idx] > A[idx + 1])
            idx++;
        return idx == A.size() - 1;
    } else
        return false;
}

int main() {
    vector<int> v{1,2,3,6,4,5};
    std::cout << validMountainArray(v) << std::endl;
    return 0;
}
