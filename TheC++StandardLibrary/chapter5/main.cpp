#include <iostream>
#include <functional>
#include <memory>
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

void testSmartPoint() {
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

int main() {
//testTuple();
testSmartPoint();

    return 0;
}
