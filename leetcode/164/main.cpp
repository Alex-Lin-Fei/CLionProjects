#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumGap(vector<int>& nums) {
    if (nums.size()<2)
        return 0;
//    计算桶大小   (max - min) / (n-1)
    int maxValue = *max_element(nums.begin(), nums.end());
    int minValue = *min_element(nums.begin(), nums.end());

    int size = max(1, (int)((maxValue - minValue) / (nums.size() - 1)));
    int bSize = (maxValue - minValue) / size + 1;
    vector<pair<int, int>> buckets(bSize, {-1, -1});

//    分桶
    for (auto &num: nums) {
//         算出对应的桶序号
        int idx = (num - minValue)/ size;
        if (buckets[idx].first == -1)
            buckets[idx] = {num, num};
        else {
            buckets[idx].first = min(buckets[idx].first, num);
            buckets[idx].second = max(buckets[idx].second, num);
        }
    }
//     遍历桶
    int pre = -1;
    int ans = 0;
    for (int i = 0; i < buckets.size(); i++) {
        if (buckets[i].first == -1)
            continue;
        else if (pre != -1){
            ans = max(ans, buckets[i].first - buckets[pre].second);
        }
        pre = i;
    }
    return ans;
}

int main() {
    vector<int>v{3,6,2,9};
    std::cout << maximumGap(v) << std::endl;
    return 0;
}
