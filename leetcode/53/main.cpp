#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    vector<int> preSum(nums.size() + 1);
    for (int i = 1; i <= nums.size(); i++)
        preSum[i] = preSum[i - 1] + nums[i - 1];
    int ans = INT32_MIN;
    for (int i = 1; i <= nums.size(); ++i)
        for (int j = 0; j < i; ++j) {
            ans = min(preSum[i] - preSum[j], ans);
        }
    return ans;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
