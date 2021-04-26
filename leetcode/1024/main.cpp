#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int videoStitching(vector<vector<int>>& clips, int T) {
    int ans = 0;
    sort(clips.begin(), clips.end(), [](vector<int> a, vector<int> b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    for(auto& v: clips)
        cout << v[0] << ' ' << v[1]<<endl;
    cout << "choose:\n";

    if (clips.back()[1] < T || clips[0][0] > 0)
        return -1;
    int idx = 0;
    int i;
    int end = 0;
    while (idx < clips.size()) {
        if(end < clips[idx][0])
            return -1;
        int temp = end;
        while (idx < clips.size() && clips[idx][0] <= end) {
            if(clips[idx][1] > temp) {
                temp = max(temp, clips[idx][1]);
                i = idx;
            }
            idx++;
        }
        cout << clips[i][0] << ' ' << clips[i][1]<<endl;

        if(temp!=end) {
            end = temp;
            ans++;
        }

        if (end >= T)
            break;
    }
    return ans;
}


int main() {
    vector<vector<int>> clips{{0, 2}, {4,8}};
    std::cout << videoStitching(clips, 5) << std::endl;
    return 0;
}
