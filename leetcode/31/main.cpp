#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int idx = nums.size() - 1;

    while (idx > 0 && nums[idx - 1] >= nums[idx])
        idx--;
    if (idx == 0)
        reverse(nums.begin(), nums.end());
    else {
        int x = nums[idx - 1];
        int t = idx - 1;
        while (idx < nums.size() && nums[idx] > x)
            idx++;
        idx--;
        swap(nums[idx], nums[t]);
        sort(nums.begin() + t + 1, nums.end());
    }

    for(auto& num : nums)
        cout<<num<<' ';
}

int main() {
    vector<int> nums{1,2,3,2,2};
    nextPermutation(nums);
    return 0;
}
