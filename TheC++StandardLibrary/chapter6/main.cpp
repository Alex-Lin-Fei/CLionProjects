#include <iostream>
#include <array>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
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

void testRange() {
    list<int> coll1{1,2,3,4,5};
    vector<int> coll2;
    coll2.resize(6);

    copy(coll1.begin(), coll1.end(), coll2.begin());
}

int main() {
//    testArray();

//    testIterator();
/*
vector<int> x {1,2,4,3,45,6};
sort(x.begin(), x.end());
    sort(x.cbegin(), x.cend());
    reverse(x.cbegin(), x.cend());
    reverse(x.begin(),x.end());

    vector<int>::iterator p = x.begin();
    vector<int>::const_iterator cp = p;
    cout << &p << ' ' << endl;
    cout << &cp<<' ' <<endl;
    *cp = 0;
    *p = 0;
    cout << *cp<<endl;
*/
/*

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
*/
testRange();
    return 0;

}
