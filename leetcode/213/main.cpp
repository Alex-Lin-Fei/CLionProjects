#include <iostream>
#include <vector>
using namespace std;

int robRange(vector<int>& nums, int s, int t) {
    vector<int> dp(t-s+1);
    dp[1] = nums[s];
    for(int i = 2; i <= t-s; i++) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1+s]);
    }
    return dp.back();
}

int rob(vector<int>& nums) {
    return max(robRange(nums, 0, nums.size()-1), robRange(nums, 1, nums.size()));
}


int main() {
    vector<int> nums{1,2,3,1};
    std::cout << rob(nums) << std::endl;
    return 0;
}
