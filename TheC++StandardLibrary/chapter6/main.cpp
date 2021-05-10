#include <iostream>
#include <array>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <iterator>

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

void testInserter() {
    list<int> coll1 = {1,2,3,4,5};

    vector<int> coll2;
    copy(coll1.begin(), coll1.end(), back_inserter(coll2));

    deque<int> coll3;
    copy(coll1.begin(), coll1.end(), front_inserter(coll3));

    set<int> coll4;
    copy(coll1.begin(), coll1.end(), inserter(coll4, coll4.begin()));


}


void testStreamIterator() {
    vector<int> coll;

    copy(istream_iterator<int>(cin),
            istream_iterator<int>(),
         back_inserter(coll));

    sort(coll.begin(), coll.end());

    unique_copy(coll.cbegin(), coll.cend(), ostream_iterator<int>(cout, "\n"));
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
//testRange();
//testInserter();
testStreamIterator();
    return 0;

}
