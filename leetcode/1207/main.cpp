#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> count;
    set<int> nums;
    for (auto &i: arr)
        count[i]++;
    for (auto &iter: count)
        nums.insert(iter.second);
    return nums.size() == count.size();
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
