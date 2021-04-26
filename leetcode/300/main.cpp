#include <iostream>
#include <vector>
using namespace std;

/*
int lengthOfLIS(vector<int>& nums) {
    if (nums.size() <= 1)
        return nums.size();
    vector<int> dp;
    dp.push_back(nums[0]);

    for (int i = 1; i < nums.size(); i++) {
        if (dp.back() < nums[i])
            dp.push_back(nums[i]);
        else {
            auto iter = lower_bound(dp.begin(), dp.end(), nums[i]);
            *iter = nums[i];
        }
    }
    return dp.size();
}
 */

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() <= 1)
        return nums.size();
    vector<int> dp(nums.size(), 1);

    int max_len = 0;

    for(int i = 0; i <nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        max_len = max(max_len, dp[i]);
    }

    return dp.size();
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
