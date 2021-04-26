#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for (auto& i: nums) {
        if (nums[abs(i)-1] < 0)
             ans.push_back(abs(i));
        else
            nums[abs(i)-1] = -nums[abs(i)-1];
    }
    for(auto& a: ans)
        cout << a <<' ';
    return ans;
}

int main() {
    vector<int> v{4,3,2,3,4,2,1,8,7};
    findDuplicates(v);
    return 0;
}
