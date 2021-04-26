#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int prev  = 0;
    int cur = 1;

    while(cur < nums.size()) {
        while (cur < nums.size() && nums[prev] == nums[cur])
            cur++;

        for (int i = prev+1; i < cur - 1;) {
            nums.erase(nums.begin() + i);
            cur--;
        }

        prev = cur;
        cur++;
    }
    for(auto& i: nums)
        cout << i <<' ';
//    return nums.size() - ans;
}

int main() {
    vector<int> v{1,1,1,2,2,3,3,3,3,4,4,4,5,5,6};
    removeDuplicates(v);
    return 0;
}
