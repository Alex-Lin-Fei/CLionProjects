#include <iostream>
#include <unordered_set>
#include <vector>
#include <array>
#include <algorithm>
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

int main() {
//    testArray();
testVector();
    return 0;
}
