#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    bool Insert = false;


    for (int i = 0; i < intervals.size(); i++) {
        vector<int> &v = intervals[i];
        if (Insert || v[1] < newInterval[0])
            ans.push_back(v);

        else if (v[0] > newInterval[1]) {
            Insert = true;
            ans.push_back(newInterval);
            ans.push_back(v);
        }

        else {
            int s = min(newInterval[0], v[0]);
            int t = max(newInterval[1], v[1]);
            while (i < intervals.size() && intervals[i][0] <= t) {
                t = max(t, intervals[i][1]);
                i++;
            }
            ans.push_back({s, t});
            Insert = true;
            if (i == intervals.size())
                break;
            i--;
        }
    }
    if(!Insert)
        ans.push_back(newInterval);

    for (auto &v: ans)
        cout << v[0] << ' ' << v[1] << endl;
    return ans;
}

int main() {
    vector<vector<int>> v {};
    vector<int> s{6, 6};
    insert(v, s);
    return 0;
}
