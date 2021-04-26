#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
        return false;
    sum /= 2;
    vector<bool> dp(sum + 1);
    dp[0] = true;
    for (int i = 1; i <= nums.size(); i++) {
        for (int j = sum; j >= nums[i - 1]; j--) {
            dp[j] = dp[j] || dp[j - nums[i - 1]];
        }
    }

    return dp.back();
}

int main() {
    vector<int> nums{1,5,11,5};
    std::cout << canPartition(nums) << std::endl;
    return 0;
}
