#include <iostream>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

map<char, vector<int>> record;

//回溯法
/*
bool backtrack(string& ring, string& key, int idx, int cur, int &count, int &limit) {
    if (cur == key.length() && count < limit) {
        return true;
    } else if (count >= limit)
        return false;
    else {
        for (auto &i: record[key[cur]]) {
            int step = min(abs(i - idx), (int) ring.length() - abs(i - idx));
            count += step;
            if (backtrack(ring, key, i, cur + 1, count, limit))
                return true;
            count -= step;
        }
    }
    return false;
}

int findRotateSteps(string ring, string key) {
    record.clear();
    for (auto &ch: key) {
        if (record.count(ch))
            continue;
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == ch)
                record[ch].push_back(i);
        }
    }
    for (auto &iter: record) {
        cout << iter.first << ": ";
        for (auto &i: iter.second)
            cout << i << ' ';
        cout << "\n**\n";
    }
    cout <<"l";
    for (int limit = 0; limit < key.length() * ring.length() / 2; limit++) {
        int count = 0;
        cout <<limit<<endl;
        if (backtrack(ring, key, 0, 0, count, limit))
            return count + key.length();
    }
    return -1;
}
*/

//分支限界法
int findRotateSteps(string ring, string key) {
    record.clear();
    for (auto &ch: key) {
        if (record.count(ch))
            continue;
        for (int i = 0; i < ring.length(); i++) {
            if (ring[i] == ch)
                record[ch].push_back(i);
        }
    }

//    估算上界和下界
   vector<int> minD;
    for (int i = 0; i < key.length() - 1; i++) {
        int tmp = INT32_MAX;
        for (auto &x: record[key[i]])
            for (auto &y: record[key[i + 1]])
                tmp = min(tmp, min(abs(x - y), (int) key.length() - abs(x - y)));
        minD.push_back(tmp);
    }
    
    int lb = accumulate(minD.begin(), minD.end(), 0);
}
int main() {
    findRotateSteps("caotmcaataijjxi"
                                 ,"oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx");
    return 0;
}
