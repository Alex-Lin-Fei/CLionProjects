#include <iostream>
#include <functional>
#include <memory>
#include <utility>
#include <vector>
using namespace std;

void testTuple() {
    std::tuple<int, float, std::string> t(77, 1.1, "more light");
    int i;
    float f;
    std::string s;
    std::tie(i,f,s) = t;
    std::cout << i << ' ' << f << ' ' << s << ' ' << std::endl;
    s = "change";
    std::cout << std::get<2>(t)<<std::endl;
    std::get<2>(t) = "aaa";
    std::cout << std::get<2>(t)<<std::endl;
    std::cout << s <<std::endl;
}

std::tuple<int> testInitializerList() {
    return {1};
}

void testSharedPoint() {
    std::shared_ptr<std::string> pNico(new std::string("nico"));
    std::shared_ptr<std::string> pJutta(new std::string("jutta"));

    (*pNico)[0]= 'N';

    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    for (auto ptr: whoMadeCoffee) {
        cout << *ptr << ' ';
    }

    cout << endl;
    *pNico = "Nicolai";

    for (auto ptr: whoMadeCoffee) {
        cout << *ptr << ' ';
    }

    cout << endl;

    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
}


class Person {
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<shared_ptr<Person>> kids;

    explicit Person(const string& n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr):
    name(std::move(n)), mother(m), father(f) {
    }

    ~Person() {
        cout << "delete " << name << endl;
    }
};


shared_ptr<Person> initFamily(const string& name) {
    shared_ptr<Person> mom(new Person(name + "`s mom"));
    shared_ptr<Person> dad(new Person(name + "`s dad"));
    shared_ptr<Person> kid(new Person(name, mom, dad));

    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    return kid;
}

void testWeakPoint() {
    shared_ptr<Person> p = initFamily("nico");

    cout << "nico`s family exists" << endl;
    cout << "- nico is shared " << p.use_count() << " times" << endl;
    cout << "- name of 1st kid of nico`s mom: " << p->mother->kids[0]->name << endl;

    p = initFamily("jim");
    cout << "jim`s family exists" << endl;
}

int main() {
//testTuple();
testSharedPoint();

    return 0;
}
