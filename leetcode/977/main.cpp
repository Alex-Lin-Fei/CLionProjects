#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& A) {
    vector<int> ans;
    for (auto &a: A)
        ans.push_back(a * a);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
