#include <iostream>
#include <vector>
using namespace std;


int largestRectangleArea(vector<int> &heights) {
    if (heights.empty())
        return 0;
    int ans = -1;
    int l, r, h;
    for (int idx = 0; idx < heights.size(); idx++) {
        if (idx > 0 && heights[idx] == heights[idx-1])
            continue;
        else {
            int i = idx;
            while (i >= 0 && heights[i] >= heights[idx])
                i--;
            int j = idx + 1;
            while (j < heights.size() && heights[j] >= heights[idx])
                j++;
//        ans = max(ans, heights[idx] * (j - i - 1));
            if (heights[idx] * (j - i - 1) > ans) {
                ans = heights[idx] * (j - i - 1);
                l = i + 1;
                r = j - 1;
                h = heights[idx];
            }
        }
    }
    cout << l << ' ' << r << ' ' << h << endl;
    return ans;
}


int main() {
    vector<int>v{1,1};
    cout << largestRectangleArea(v);
    return 0;
}
