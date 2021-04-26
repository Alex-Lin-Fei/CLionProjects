#include <iostream>
#include <vector>
#include <complex>
using namespace std;

//2.2.1
//2.2.3 常量表达式 (const expression) 在编译时求值
constexpr double square(double x) {
    return x * x;
}


void print_square(double x) {
    cout << "the square of " << x << " is " << square(x)<<"\n";
}

//2.2.2
void some_function() {
    double d = 2.2;
    int i = 7;
    d = d + i;
    i = d * i; //把乘积结果赋给i(d*i是一个double值，在这里被截成iint值
}

//2.2.4
bool accept() {
    cout << "Do you want to proceed(y or n)?\n";

    char answer = 0;
    cin >> answer;

    if (answer == 'y')
        return true;
    return false;
}

bool accept2() {
    cout << "Do you want to proceed(y or n)?\n";

    char answer = 0;
    cin >> answer;
    switch(answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "I`ll take that for a no.\n";
            return false;
    }
}

bool accept3() {
    int tries = 1;
    while(tries < 4) {
        cout << "Do you want to proceed(y or n)?\n";

        char answer = 0;
        cin >> answer;
        switch(answer) {
            case 'y':
                return true;
            case 'n':
                return false;
            default:
                cout << "Sorry, I don`t understand that.\n";
                ++tries;
        }
    }
    cout << "I`ll take that for a no.\n";
    return false;
}

//2.2.5
void copy_fct() {
    int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[10];

    for (auto i = 0; i != 10; i++)
        v2[i] = v1[i];
//    ……
}

void print() {
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto x: v)
        cout << x << '\n';
    for (auto x: {10, 21, 32, 43, 54, 65})
        cout << x << '\n';
    // ……
}


void increment() {
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto& x: v)
        ++x;
    for (auto x: v)
        cout << x << '\n';
//    ……
}

int count_x(char *p, char x) {
    if (p == nullptr)
        return 0;
    int count = 0;
    for (; *p != 0; ++p)
        if (*p == x)
            ++count;
    return count;
}

//2.3.1 结构
/*
struct Vector{
    int sz; //元素的数量
    double * elem; //指向元素的指针
};

void vector_init(Vector& v, int s) {
    v.elem = new double[s];
    v.sz = s;
}

double read_and_sum(int s) {
    Vector v;
    vector_init(v, s);
    for (int i = 0; i < s; ++i)
        cin >> v.elem[i];

    double sum = 0;
    for (int i = 0; i != s; ++i)
        sum += v.elem[i];
    return sum;
}

void f(Vector v, Vector& rv, Vector* pv) {
    int i1 = v.sz;
    int i2 = rv.sz;
    int i3 = pv->sz;
}
 */

//2.3.2 class
/*
class Vector{
public:
    Vector(int s): elem{new double[s]}, sz{s}{}
    double& operator[](int i) {return elem[i];}
    int size() {return sz;}
private:
    double *elem;
    int sz;
};
 */

//2.4

class Vector{
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double *elem;
    int sz;
};

Vector::Vector(int s)
:elem{new double[s]}, sz{s} {
}

double& Vector::operator[](int i) {return elem[i];}

int Vector::size() {return sz;}
//2.3.3 枚举
enum class Color {red, blue, green};
enum class Traffic_light {green, yellow, red};

Traffic_light& operator++(Traffic_light& t, int) {
    switch (t) {
        case Traffic_light::green:
            return t = Traffic_light::yellow;
        case Traffic_light::yellow:
            return t = Traffic_light::red;
        case Traffic_light::red:
            return t = Traffic_light::green;
    }
}


void Judge(Traffic_light& t) {
    switch (t) {
        case Traffic_light::green:
            cout << "Traffic_light::green"<<endl;
            break;
        case Traffic_light::yellow:
            cout << "Traffic_light::yellow" <<endl;
            break;
        case Traffic_light::red:
            cout << "Traffic_light::red"<<endl;
            break;
    }
}


//2.4.2
namespace My_code{
    class complex{

    };

    int main();
}

int My_code::main() {

}

//2.4.3

constexpr double C = 2999.9;

void f(double speed) {
    constexpr double local_max = 160.0/(60*60);

    static_assert(speed<C, "can`t go that fast"); //error:错误 速度必须为常量
    static_assert(local_max<C, "can`t go that fast");
}
const int ll = 0;

int main() {
//    2.2.1
    print_square(1.234);

//    2.2.2
//    初始化器列表
    double d1 = 2.3;
    double d2{2.3};

    complex<double> z = 1;
    complex<double> z2{d1, d2};
    complex<double> z3 = {1, 2}; //当使用{……}时，=是可选的

    vector<int> v{1, 2, 3, 4, 5, 6};

    int i1 = 7.2;
//    int i2{7.2};//错误：试图执行浮点数向整数的类型转换
//    int i3 = {7.2}; // =是多余的

//    在定义一个变量时，如果变量的类型可以由初始化器推测得到，无需显式指定其类型
    auto b = true;
    auto ch = 'x';
    auto i = 123;
    auto y = sqrt(i);

//    2.2.3
//    const 把变量传入函数时不必担心变量被改变  constexpr ”在编译时求值“
    const int dmv = 17; //命名的常量
    int var = 17; //不是常量
    constexpr double max1 = 1.4 * square(dmv); // 如果square(17)是常量表达式，则true
//    constexpr double max2 = 1.4 * square(var); //var不是常量表达式
    const double max3 = 1.4 * square(var); //OK 可在运行时求值
//    double sum(const vector<int> &); //sum不会改变参数的值
//    vector<double> vec{1.2, 3.4, 4.5};
//    const double s1 = sum(v);
//    constexpr double s2 = sum(v); //sum(v)不是常量表达式

//    2.2.5
    char cv[6] = {8, 8, 8, 1, 3, 2}; //含有6个字符的数组
    char *p; //该指针指向字符

    p = &cv[3]; //p指向v的第4个元素
    char x = *p; //*p是p的内容

    copy_fct();
    print();

    increment();

    p = cv;
    std::cout << count_x(p, 8) << std::endl;

//    2.3.3
/*
    Color col = Color::red;
    Traffic_light light= Traffic_light::red;

    Color l = red; //error:哪个red
    Color m = Traffic_light::red; //错误：这个red不是Color的对象
    Color n = Color::red; //yes

//    不能隐式混用Color和整数值
   int i = Color::red; //error: Color::red 不是一个int
   Color c = 2; //error：2不是一个Color对象
   */

    Traffic_light light = Traffic_light::green;
    cout << "light:\n";
    Judge(light);
    Traffic_light next = light++;
    cout << "next:\n";
    Judge(next);
    Judge(light);

//    2.4.3
    constexpr double local_max = 160.0/(60*60);

    static_assert(local_max<C, "can`t go that fast");
    const int a = ll;
    constexpr int bb = a;
    constexpr int cc = bb;



    return 0;
}
