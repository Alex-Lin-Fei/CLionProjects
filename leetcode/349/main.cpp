#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> same;
    set<int> s;
    for (auto &i: nums1)
        s.insert(i);
    for (auto &i: nums2)
        if (s.count(i)) {
            same.push_back(i);
            s.erase(i);
        }
    return same;
}

class T{
private:
    static int a;
public:
    static int b;
    void fun() const {
        //f();
    }

    void f() {

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
