#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) {
        return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];
    });

    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (end < intervals[i][0]) {
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        } else
            end = max(intervals[i][1], end);
    }
    ans.push_back({start, end});
    for(auto& i: ans)
        cout << i[0] <<' ' << i[1]<<endl;
    return ans;
}

int main() {
    vector<vector<int>> intervals{{3,3}, {1,3}, {2,6}, {8, 10}, {15, 18}};
    merge(intervals);
    return 0;
}
