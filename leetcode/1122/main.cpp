#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> rank;
    for (int i = 0; i < arr2.size(); i++)
        rank[arr2[i]] = i;
    sort(arr1.begin(), arr1.end(), [&](int a, int b) {
        if (rank.count(a))
            return rank.count(b) == 0 || rank[a] < rank[b];
        else
            return rank.count(b) == 0 && a < b;
    });
    for (auto &i: arr1)
        cout << i << ' ';
    return arr1;
}

int main() {
    vector<int> arr1{2,3,1,3,2,4,6,7,9,2,19}, arr2{2,1,4,3,9,6};
    relativeSortArray(arr1, arr2);
    return 0;
}
