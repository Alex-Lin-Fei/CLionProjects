#include <iostream>
#include <unordered_set>
#include <vector>
#include <array>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;


typedef array<string, 5> FiveStrings;
void testArray() {
    array<int, 5> a = {1,2,3,4};
    array<int, 5> b({5,4,3,2,1});
//vector<int> a{1,2,3,4,0};
//vector<int> b{5,4,3,2,1};
    array<int, 5> c{1,2,3,4,5};
    for (auto& i: a) {
        cout << i << ' ' ;
    }
    cout << endl;

    for (auto& i: b) {
        cout << i << ' ' ;
    }
    cout << endl;

    for (auto& i: c) {
        cout << i << ' ' ;
    }
    cout << endl;

    auto pa = a.begin();
    auto pb = b.begin();
    auto ra = &a[0];
    auto rb = &b[0];

    cout << "pa: " << &*pa<<endl;
    cout << "pb: " << &*pb<<endl;
    cout << "ra: " << ra<<endl;
    cout << "rb: " << rb<<endl;
    cout << "a.begin(): " << &*a.begin()<<endl;
    cout << "b.begin(): " << &*b.begin()<<endl;
    cout << "*pa: " << *pa<<endl;
    cout << "*pb: " << *pb<<endl;
    cout << "*ra: " << *ra<<endl;
    cout << "*rb: " << *rb<<endl;
    cout << "*a.begin(): " << *a.begin()<<endl;
    cout << "*b.begin(): " << *b.begin()<<endl;
    swap(a, b);
    cout << "pa: " << &*pa<<endl;
    cout << "pb: " << &*pb<<endl;
    cout << "ra: " << ra<<endl;
    cout << "rb: " << rb<<endl;
    cout << "a.begin(): " << &*a.begin()<<endl;
    cout << "b.begin(): " << &*b.begin()<<endl;
    cout << "*pa: " << *pa<<endl;
    cout << "*pb: " << *pb<<endl;
    cout << "*ra: " << *ra<<endl;
    cout << "*rb: " << *rb<<endl;
    cout << "*a.begin(): " << *a.begin()<<endl;
    cout << "*b.begin(): " << *b.begin()<<endl;

    FiveStrings f ={"Hello", "world", "nico", "are"};
    cout << tuple_size<FiveStrings>::value<<endl;
    cout << typeid(tuple_element<1, FiveStrings>::type).name()<<endl;
    cout << typeid(std::string).name()<<endl;

    cout << get<1>(f)<<endl;
}

void testVector() {
    vector<string> sentence;

    sentence.reserve(5);

    sentence.push_back("Hello, ");
    sentence.insert(sentence.end(), {"how", "are", "you", "?"});

    copy(sentence.cbegin(), sentence.cend(),
         ostream_iterator<string>(cout, " "));

    cout << endl;

    cout << " max_size(): " << sentence.max_size()<<endl;
    cout << " size(): " << sentence.size()<<endl;
    cout << " capacity(): " << sentence.capacity()<<endl;

    auto one = sentence.begin()+1;
    auto two = sentence.begin()+2;
    cout << &*one << ' ' << &*two<<endl;
    cout << *one << ' ' << *two<<endl;
    swap(sentence[1],sentence[2]);
    cout << &*one << ' ' << &*two<<endl;
    cout << *one << ' ' << *two<<endl;

    sentence.insert(find(sentence.begin(), sentence.end(), "?"), "always");

    sentence.back() = "!";


    copy(sentence.cbegin(), sentence.cend(),
         ostream_iterator<string>(cout, " "));

    cout << endl;

    cout << " max_size(): " << sentence.max_size()<<endl;
    cout << " size(): " << sentence.size()<<endl;
    cout << " capacity(): " << sentence.capacity()<<endl;

}


void printList(const list<int> & l1, const list<int> l2) {
    cout << "List 1: ";
    copy(l1.cbegin(), l1.cend(), ostream_iterator<int>(cout, " "));
    cout << endl<<"List 2: ";
    copy(l2.cbegin(), l2.cend(), ostream_iterator<int>(cout, " "));
    cout << endl<<endl;
}

void testList() {
    list<int> list1, list2;

    for (int i = 0; i < 6; i++) {
        list1.push_back(i);
        list2.push_front(i);
    }

    printList(list1, list2);

    list2.splice(find(list2.begin(), list2.end(), 3), list1);

    printList(list1, list2);
    list2.splice(list2.end(), list2, list2.begin());

    printList(list1, list2);

    list2.sort();
    list1 = list2;
    list2.unique();
    printList(list1, list2);

    list1.merge(list2);

    printList(list1, list2);
}

int main() {
//    testArray();
//testVector();
testList();
    return 0;
}
