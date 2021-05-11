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
    array<int, 5> nums{};
    for (auto &i: nums)
        cout << i << ' ';
    cout << endl;
    list<int> l{1, 2, 3};
    cout << l.front() << ' ' << l.back();
}

void testIterator() {
    list<char> cls{'a', 'b', 'c', 'd'};

    list<char>::const_iterator pos;
    for (pos = cls.begin(); pos != cls.end(); pos++) {
//        *pos = *pos + 1;
        cout << *pos << ' ';
    }
    cout << endl;

}

void testRange() {
    list<int> coll1{1, 2, 3, 4, 5};
    vector<int> coll2;
    coll2.resize(6);

    copy(coll1.begin(), coll1.end(), coll2.begin());
}

void testInserter() {
    list<int> coll1 = {1, 2, 3, 4, 5};

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

void testRemove() {
    list<int> coll;

    for (int i = 1; i <= 6; i++) {
        coll.push_back(i);
        coll.push_front(i);
    }

    cout << "Pre: ";
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    remove(coll.begin(), coll.end(), 3);

    cout << "Post: ";
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void testRemoveII() {
    list<int> coll;

    for (int i = 1; i <= 6; i++) {
        coll.push_back(i);
        coll.push_front(i);
    }

    cout << "Pre: ";
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    list<int>::iterator end = remove(coll.begin(), coll.end(), 3);
    copy(coll.begin(), end, ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "number of removed elements: " << distance(end, coll.end()) << endl;

    coll.erase(end, coll.end());

    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}


void testErase() {
    set<int> coll = {1, 2, 3, 4, 5, 6};
    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

//    int num = coll.erase(3);
//
//    cout << "number of removed elements: " << num << endl;
//    copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
//    cout << endl;
    for (auto pos = coll.begin(); pos != coll.end();) {
        if (*pos == 3) {
            coll.erase(pos++);
//            cout << *pos<<' ';
        } else {
            cout << *pos++ << ' ';
        }
    }
}

void print(int elem) {
    cout << elem << ' ';
}

void testForEach() {
    vector<int> coll;

    for (int i = 1; i <= 9; ++i) {
        coll.push_back(i);
    }
    for_each(coll.begin(), coll.end(), print);

    cout << endl;
}

int square(int value) {
    return value * value;
}

void testTransform() {
    set<int> coll1;
    vector<int> coll2;

    for (int i = 1; i <= 9; ++i) {
        coll1.insert(i);
    }

    for_each(coll1.begin(), coll1.end(), print);
    cout << endl;
    transform(coll1.begin(), coll1.end(),
              back_inserter(coll2),
              square);
    for_each(coll2.begin(), coll2.end(), print);
}


bool isPrime(int number) {
    number = abs(number);

    if (number < 2)
        return false;
    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor) {
        ;
    }
    return divisor == 1;
}

void testFindIf() {
    list<int> coll;

    for (int i = 24; i <= 30; ++i) {
        coll.push_back(i);
    }


//    auto pos = find_if(coll.begin(), coll.end(), isPrime);
//    if (pos != coll.end())
//        cout << *pos<< " is first prime number found" << endl;
//    else
//        cout <<"no prime number found \n";
    transform(coll.begin(), coll.end(), coll.begin(), [](double d) {
        return d * d;
    });
    copy(coll.begin(),coll.end(), ostream_iterator<int>(cout, " "));
}

class Person {
private:
    string fname;
    string lname;
public:
    Person(string&& f, string&& l) {
        fname = f;
        lname = l;
    }
    string firstname() const {
        return fname;
    }
    string lastname() const {
        return lname;
    }
};

bool my_operator(Person& p1, Person& p2) {
    return p1.firstname() < p2.firstname();
}

void testBinaryPredicate() {
    vector<Person> persons{Person("Jack", "smith"), Person("Kary", "black")};
    sort(persons.begin(), persons.end(), my_operator);

    cout << persons[0].firstname() << ' ' << persons[0].lastname() << endl;
    cout << persons[1].firstname() << ' ' << persons[1].lastname() << endl;
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

typedef std::set< int> IntSet;

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
//testStreamIterator();
//    testRemove();
//testErase();
//testForEach();
//    testTransform();
//testFindIf();
//testBinaryPredicate();
    return 0;
}
