#include <iostream>
#include <array>
#include <list>
#include <set>
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

void testIterator() {
    list<char> cls{'a', 'b', 'c', 'd'};

    list<char>::const_iterator pos;
    for (pos = cls.begin(); pos != cls.end(); pos++) {
//        *pos = *pos + 1;
        cout << *pos<<' ';
    }
    cout << endl;

}



int main() {
//    testArray();

//    testIterator();
typedef std::set<int> IntSet;

IntSet coll;

coll.insert(3);
    coll.insert(1);
    coll.insert(5);
    coll.insert(4);
    coll.insert(1);
    coll.insert(6);
    coll.insert(2);

    IntSet::const_iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos<<' ';
    }

    cout << endl;

    return 0;
}
