#include <iostream>
#include <vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    vector<int> down(nums.size()), up(nums.size());
    down[0] = up[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1]) {
            up[i] = down[i - 1] + 1;
            down[i] = down[i - 1];
        } else if (nums[i] < nums[i - 1]) {
            down[i] = up[i - 1] + 1;
            up[i] = up[i - 1];
        } else {
            down[i] = down[i - 1];
            up[i] = up[i - 1];
        }
    }
    return max(down.back(), up.back());
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
