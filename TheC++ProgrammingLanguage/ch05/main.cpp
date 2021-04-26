#include <iostream>
#include <queue>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <complex>
#include <mutex>
#include <list>
#include <condition_variable>
#include <future>
#include <numeric>
#include <random>
#include <functional>

using namespace std;
using namespace std::chrono;

//5.3.1
/*
void f(){
 cout << "Hello";
}

struct F {
    void operator()() {
        cout << "Parallel world";
    }
};

void user() {
    thread t1{f};
    thread t2{F()};

    t1.join();
    t2.join();
}
 */

//5.3.2
/*
void f(vector<double> v) {
    for (auto &i: v)
        cout << i << ' ';
    cout << endl;
}

struct F {
    vector<double> &v;

    F(vector<double> &vv) : v{vv} {}

    void operator()();
};

void F::operator()() {
    for (auto &i: v)
        cout << i << ' ';
    cout << endl;
}
 */

//5.3.3
/*
void f(const vector<double>& v, double* res);

class F {
public:
    F(const vector<double> &vv, double *p) : v{vv}, res{p} {}

    void operator()();

private:
    const vector<double> &v;
    double *res;
};
 */

//5.3.4
/*
mutex m; //控制共享数据访问的mutex
int sh; //共享的数据

void f() {
    unique_lock<mutex> lck{m};
    sh += 7;
}

class Message{
//    ...
};

void do_word();

queue<Message> mqueue;
condition_variable mcond;
mutex mmutex;

void consumer() {
    while (true) {
        unique_lock<mutex> lck{mmutex}; //获取锁
        while (mcond.wait(lck))
            ;
        auto m = mqueue.front();
        mqueue.pop();
        lck.unlock();
//        deal for m
    }
}

void producer() {
    while (true) {
        Message m;
        unique_lock<mutex> lck{mmutex};
        mqueue.push(m);
        mcond.notify_one();
    }
}

template<typename X>
void f(promise<X> & px) {
    try{
        X res;
        px.set_value(res);
    }
    catch () {
        px.set_exception(current_exception());
    }
}

template<typename X>
void g(future<X>& px) {
    try{
        X v = px.get();
    } catch () {

    }
}


*/
//5.4.1
void do_word() {
    cout << "hello, world"<<endl;
}


//5.6 数学计算
void f1() {
    list<double> lst{.9, 0.8, 0.6};
//    注意，accumulate 函数第三个参数　初值　赋值的时候一定要注意
//    所累加的vector　的类型，如果vector　是float, 赋值的时候如果给０
//    　而不是０．０，那么就会出现累加的小于１的数都是０；
    auto s = accumulate(lst.begin(),lst.end(), .0);
    cout << s <<'\n';
}

//5.6.2 复数
void f2(complex<float> fl, complex<double> db) {
    complex<long double> ld{fl + sqrt(db)};
    db += fl * 3;
    fl = pow(1 / fl, 2);
}

class Rand_int {
public:
    Rand_int(int low, int high) : dist{low, high} {

    }

    int operator()() { return dist(re); }

private:
    default_random_engine re;
    uniform_int_distribution<> dist;
};


int main() {
//    5.3.1
//    user();
/*
    vector<double> some_vec{1,2,3,4,5,6,7,8};
    vector<double> vec2{10, 11, 12, 13, 14};

    thread t1{f, some_vec};
    thread t2{F{vec2}};

    t1.join();
    t2.join();
*/
//5.3.3
/*
    vector<double> some_vec;
    vector<double> vec2;

    double res1;
    double res2;
    thread t1{f, some_vec, &res1};
    thread t2{F{vec2, &res2}};

    t1.join();
    t2.join();

    cout << res1 <<' ' << res2<<'\n';
    */

//5.4.1

    auto t0 = high_resolution_clock::now();
    do_word();
    auto t1 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1 - t0).count() << "msce\n";

//5.4.3
    tuple<string, int, double> t2("Sild", 123, 3.14);
    auto t = make_tuple(string("Herring"), 10, 1.23);

    string s = get<0>(t);
    int x = get<1>(t);
    double y = get<2>(t);
    cout << s << ' ' << x << ' ' << y << endl;
//    5.6
    f1();

//    5.6.3 random
    using my_engine = default_random_engine; //引擎类型 负责生成一组随机值或者伪随机值
    using my_distribution = uniform_int_distribution<>; //分布类型 负责把引擎产生的值映射到某个数学分布上

    my_engine re{}; //默认引擎
//    default_random_engine  r{};
    my_distribution one_to_six{1, 6}; // 该分布把随机数映射到1～6的范围
    auto die = bind(one_to_six, re);  //得到一个随机数生成器
    int num = die(); //掷骰子
    cout << num;

    Rand_int rnd{0, 4};
    vector<int> histogram(5);
    for (int i = 0; i != 200; i++)
        ++histogram[rnd()];
    for(int i = 0; i != mn.size(); ++i) {
        cout << i << '\t';
        for (int j = 0; j != mn[i]; j++)
            cout << '*';
        cout << endl;
    }






    return 0;
}

