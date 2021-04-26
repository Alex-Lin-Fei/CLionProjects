#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//4.2
string compose(const string& name, const string & domain) {
    return name + '@' + domain;
}

void m2(string & s1, string & s2) {
    s1 = s1 + '\n';
    s2 += '\n';
}

string name = "Niels Stroustrup";

void m3() {
    string s = name.substr(6, 10);
    name.replace(0, 5, "nicholas");
    cout << name<<endl;
    name[0] = toupper(name[0]);
    cout << name<<endl;
}

string incantaion;

void respond(const string & answer) {
    if (answer == incantaion) {
//        执行一些操作
    }
    else if (answer == "yes") {
//        ……
    }
//    ……
}


//4.3.1
/*
void f() {
    cout << 10;
}

void g() {
    int i{10};
    cout << i;
}

void h(int i) {
    cout << "the value of i is ";
    cout << i;
    cout <<'\n';
}

void h2(int i) {
    cout << "the value of i is " << i << '\n';
}

void k() {
    int b = 'b';
    char c = 'c';
    cout << 'a' << b << c;
}
*/

//4.3.2
void f() {
    int i;
    cin >> i;

    double d;
    cin >> d;
    cout << i << ' '<< d<<endl;
}

void hello() {
    cout << "please enter your name\n";

    string str;
    cin >> str;
    cout << "Hello, " << str << "!\n";
}

void hello_line() {
    cout  << "Please enter your name\n";
    string str;
    getline(cin, str);
    cout << "Hello, " << str << "!\n";
    getline(cin, str);
    cout << "Hello, " << str << "!\n";
}

//4.3.3

struct Entry {
    string name;
    int number;
};

ostream& operator<<(ostream& os, const Entry & e) {
    return os << "{\"" << e.name << "\", " << e.number<<"}";
}

istream& operator>>(istream& is, Entry& e) {
    char c, c2;
    if (is >> c && c == '{' && is >>c2 && c2 == '\"') {
        string name ;
        while (cin.get(c) && c != '\"')
            name+=c;
        if (is >> c && c == ','){
            int number= 0;
            if (is >>number>>c && c == '}')
            {
                e= {name, number};
                return is;
            }
        }
    }
//    is.setf(ios_base::failbit);
    return is;
}

//4.4.1

void print_book(const vector<Entry> & book) {
    for (int i = 0; i != book.size(); i++)
        cout << book[i] << '\n';

    for(const auto& x: book)
        cout <<x <<'\n';
}

template <typename T>
class Vec: public std::vector<T> {
public:
    using vector<T>::vector;

};

//4.4.2
/*
list<Entry> phone_book = {
        {"David Hume", 123456},
        {"Kari Popper", 23456},
        {"Bertrand Arthur William Russell", 34567}
};

int get_number(const string & s) {
//    for (const auto &x: phone_book)
//        if (x.name == s)
//            return x.number;
    for (auto p = phone_book.begin(); p != phone_book.end(); ++p)
        if (p->name == s)
            return p->number;
    return 0;
}

void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q) {
    phone_book.insert(p, ee);
    phone_book.erase(q);
}
*/

//4.4.3 map
/*
map<string, int> phone_book = {
        {"David Hume",                      123456},
        {"Kari Popper",                     23456},
        {"Bertrand Arthur William Russell", 34567}
};

int get_number(const string & s) {
    return phone_book[s];
}
*/
//4.4.4 unordered_map
unordered_map<string ,int> phone_book = {
        {"David Hume",                      123456},
        {"Kari Popper",                     23456},
        {"Bertrand Arthur William Russell", 34567}
};

int get_number(const string & s) {
    return phone_book[s];
}

//4.5
bool operator<(const Entry& x, const Entry& y) {
    return x.name < y.name;
}

void f(vector<Entry> &vec, list<Entry> & lst) {
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), lst.begin());
}

list<Entry> f(vector<Entry> & vec) {
    list<Entry> res;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(res));
    return res;
}

//4.5.1
bool has_c(const string & s, char c) {
//    auto p = find(s.begin(), s.end(), c);
//    if (p != s.end())
//        return true;
//    else
//        return false;
    return find(s.begin(), s.end(), c) != s.end();
}


vector<string::iterator> find_all(string & s, char c) {
    vector<string::iterator> res;
    for (auto p = s.begin(); p != s.end(); p++)
        if (*p == c)
            res.push_back(p);
    return res;
}

void test() {
    string m{"Mary had a little lamb"};
    for (auto p: find_all(m, 'a'))
        if (*p != 'a')
            cerr << "a bug\n";
}


template <typename C, typename V>
vector<typename C::iterator> find_all(C& c, V v) {
    vector<typename C::iterator> res;
    for (auto p = c.begin(); p != c.end(); ++p)
        if (*p == v)
            res.push_back(p);
    return res;
}

void test2() {
}

//4.5.4

struct Greater_than {
    int val;

    Greater_than(int v) : val{v} {}

    bool operator()(const pair<string, int> &r) { return r.second > val; }
};

bool cmp(const pair<string, int>& r) {
    return r.second<45;
}

void f(map<string, int> & m) {
    auto p = find_if(m.begin(), m.end(), Greater_than{42});
}


//4.5.6

namespace Estd {
    using namespace std;

    template<typename C>
    void sort(C &c) {
        sort(c.begin(), c.end());
    }

    template<class C, class Pred>
    void sort(C &c, Pred p) {
        sort(c.begin(), c.end(), p);
    }
}

int main() {
    auto addr = compose("dmr", "bell-lab");
    std::cout << addr << std::endl;
//4.2
    m3();

//    4.3.1
/*
    f();
    g();
    cout << endl;
    h(10);
    h2(10);
    k();
    */

//    4.3.2
/*
    f();
    hello();

    hello_line();

    Entry entry = Entry();
    entry.name = "liuyongfei";
    entry.number = 111;
    cout << entry << " hello ";
    cin >> entry;
    cout << entry;
    */

//    4.4.1

    vector<Entry> v_phone_book = {
            {"David Hume",                      123456},
            {"Kari Popper",                     23456},
            {"Bertrand Arthur William Russell", 34567}
    };


//    4.5
    test();

//    4.5.4
    map<string, int> m;
    int cxx = count_if(m.begin(), m.end(), [](const pair<string, int> &r) { return r.second > 42; });

    return 0;
}
