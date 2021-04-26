#include <iostream>
#include <vector>
#include <map>
using namespace std;

class RandomizedCollection {
private:
    map<int, int> m;
//    vector<int> nums;
public:
    vector<int>nums;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        m.clear();
        nums.clear();
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool contains = false;
        if (++m[val] == 1)
            contains = true;
        nums.push_back(val);
        return contains;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m[val]) {
            m[val]--;
            for (auto it = nums.begin(); it != nums.end(); it++)
                if (*it == val) {
                    nums.erase(it);
                    break;
                }
            return true;
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int x = random() % nums.size();
        auto it = nums.begin();
        for (int i = 0; i < x; i++)
            it++;
        return *it;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    RandomizedCollection randomizedCollection = RandomizedCollection();
    cout <<randomizedCollection.insert(1)<<endl;
    cout <<randomizedCollection.insert(1)<<endl;
    cout <<randomizedCollection.insert(2)<<endl;
    cout << randomizedCollection.getRandom()<<endl;
    cout << randomizedCollection.remove(1)<<endl;
    for(int & num : randomizedCollection.nums)
        cout <<num<<' ';
    cout << endl;
    cout << randomizedCollection.getRandom()<<endl;



    return 0;
}
