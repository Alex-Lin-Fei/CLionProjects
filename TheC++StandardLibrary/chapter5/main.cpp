#include <iostream>
#include <functional>

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

int main() {
testTuple();

    return 0;
}
