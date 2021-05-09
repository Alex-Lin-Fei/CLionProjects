#include <iostream>
#include <array>
#include <list>
#include <unordered_set>
using namespace std;

void testArray() {
    array<int, 5> nums{} ;
    for (auto& i: nums)
        cout << i << ' ';
    cout << endl;
    list<int> l{1,2,3};
    cout << l.front() << ' ' << l.back();
}


int main() {
//    testArray();

    unordered_multiset<string> cities{
            "Braunschweig", "Hanover", "Frankfurt", "New York", "Chicago", "Toronto", "Paris", "Frankfurt"
    };

    for (const auto &elem: cities) {
        cout << elem << " ";
    }
    cout << endl;

    cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

    for (const auto &elem: cities) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
