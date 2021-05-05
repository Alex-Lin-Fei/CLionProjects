#include <iostream>
#include <vector>
#include <complex>
#include <map>

//3.1.2 uniform initialization initializer list
void a() {
    int values[]{1, 2, 3};
    std::vector<int> v{2, 3, 4};
    std::vector<std::string> cities{
            "Berlin", "New York", "London"
    };
    std::complex<double> c{4.0, 3.0};

//    value initialization

    int i; //undefined value
    int j{}; //0
    int *p; //undefined value
    int *q{}; //nullptr

//narrowing
    int x1(5.3); //5
    int x2 = 5.3; //5
    //int x3{5.3}; //error
    //int x4 = {5.3}; //error
    char c1{7};
    //char c2{9999}; //error 9999does not fit into a char
    std::vector<int> v1{1, 2, 3, 4}; //ok
    //std::vector<int> v2{1, 2.3, 4, 5.6}; //error double -> int
}

// print({1,2,3,4,5})
void print(std::initializer_list<int> values) {
    for (auto p = values.begin(); p != values.end(); ++p)
        std::cout << *p << '\n';
}

class P {
public:
    P(int, int) {
        std::cout << "this is (int, int)\n";
    }

    P(std::initializer_list<int>) {
        std::cout << "this is initializer list" << std::endl;
    }

    ~P() {
        std::cout << "object destroyed\n";
    }
};


//检验类对象传参是是否为一个临时对象
void foo(P p) {
    std::cout << "this is foo\n";
}

void test() {
    P p1{1, 2};
    foo(p1);
}

//lambda capture
void capture() {
    int x = 0;
    int y = 42;
    x = y = 77;

    auto qqq = [x, &y] {
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        ++y;
    };
    qqq();
    qqq();
    std::cout << "final x: " << x << std::endl;
    std::cout << "final y: " << y << std::endl;
}


template<typename T, typename container = std::vector<T>>
class MyClass {
    T x;
public:
    container c;
};

int main() {
//    P p(77,5);
//    P q{77,5};
//    P r{77,5, 3};
//    P s = {77,5};

//    test();
//    constexpr int x = 10;
//    int url[x] = {0};

    capture();


    std::map<std::string, float> coll;
    decltype(8) elem;
    std::cout << typeid(elem).name() << std::endl;
    MyClass<int> m{};
    m.c.push_back(1);
    std::cout << typeid(m.c).name()<<std::endl;

    return 0;
}
