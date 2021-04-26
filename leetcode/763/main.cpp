#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> partitionLabels(string S) {
    vector<int> ans;
    vector<pair<int, int>> space;
    set<char> s;

    for (auto c: S)
        s.insert(c);

    for (auto &c: s)
    {
        int start = find(S.begin(), S.end(), c) - S.begin();
        int end = find(S.rbegin(), S.rend(), c) - S.rbegin();
        space.emplace_back(start, S.length() - end - 1);
    }


    sort(space.begin(), space.end());
    int l=space[0].first, r = space[0].second;
    for(auto& sp: space) {
        if (r < sp.first) {
            ans.emplace_back(r-l+1);
            l = sp.first;
            r = sp.second;
        }
        else
            r = max(r, sp.second);
    }
    ans.emplace_back(r-l+1);

//    ans.erase(ans.begin());
    for(auto& i: ans)
        cout <<i <<' ';
    return ans;
}

int main()
{
    string S = "ababcbacadefegdehijhklij";
    partitionLabels(S);


    return 0;
}






