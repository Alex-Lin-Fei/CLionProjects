#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {
    vector<int> ans(A.size());
    int pOdd = 0;
    int pEven = 0;
    for (int i = 0; i < A.size(); i++) {
//        奇数序号
        if (i % 2) {
            while (pOdd < A.size() && A[pOdd] % 2 == 0)
                pOdd++;
            ans[i] = A[pOdd];
            pOdd++;
        }
//        偶数序号
        else{
            while (pEven < A.size() && A[pEven] % 2)
                pEven++;
            ans[i] = A[pEven];
            pEven++;
        }
    }
    for(auto& i: ans)
        cout << i << ' ';
    return ans;
}

int main() {
    vector<int> v{4,2,5,7};
    sortArrayByParityII(v);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
