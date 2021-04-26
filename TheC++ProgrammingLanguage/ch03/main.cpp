#include <iostream>
#include <list>
#include <memory>
#include <vector>
using namespace std;
/*
//3.2
class complex{
    double re, im;
public:
    complex(double r, double i): re{r}, im{i}{}
    complex(double r): re{r}, im{0}{}
    complex(): re{0}, im{0}{}

    double real() const {return re;}
    void real(double d) { re = d; }
    double image() const {return im;}
    void image(double d) {im = d;}
    complex& operator+=(complex z) {re += z.re; im+= z.im; return *this; }
    complex& operator-=(complex z) {re -= z.re; im-= z.im; return *this; }
    complex& operator*=(complex z);
    complex& operator/=(complex z);

//    complex& operator+(complex& z) {re += z.re; im+= z.im; return *this; }

//    friend complex operator+(complex a, complex b) { return a+=b;}




};


complex operator+(complex a, complex b) { return a+=b;}
complex operator-(complex a) { return {-a.real(), -a.image()};}
complex operator-(complex a, complex b) { return a-=b;}
complex operator*(complex a, complex b) { return a*=b;}
complex operator/(complex a, complex b) { return a/=b;}

bool operator==(complex a, complex b) {
    return a.real() == b.real() && a.image() == b.image();
}

bool operator!= (complex a, complex b) {
    return !(a == b);
}

void f(complex z) {
    complex a{2.3};
    complex b{1 / a};
    complex c{a + z * complex{1, 2.3}};

    if (c != b)
        c = -(b / a) + 2 * b;
}

//Container
class Vector {
private:
    double * elem;
    int sz;
public:
    Vector(int s): elem{new double[s]}, sz{s} {
        for (int i = 0; i != s; ++i)
            elem[i] = 0;
    }
    Vector();

    Vector(std::initializer_list<double>);
    void push_back(double);

    ~Vector(){
        delete[] elem;
    }
    double& operator[](int i);

    int size()const;
};


Vector::Vector(std::initializer_list<double> lst)
:elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())} {
    copy(lst.begin(), lst.end(), elem);
}



Vector read(istream& is) {
    Vector v;
    for(double d; is>>d;)
        v.push_back(d);
    return v;
}

//3.2.2
class Container{
public:
    virtual double & operator[](int i) = 0;
    virtual int size() const=0;
    virtual ~Container(){}
};

void use(Container& c) {
    const int sz = c.size();

    for (int i = 0; i != sz; ++i)
        cout << c[i] << endl;
}

class Vector_container: public Container {
    Vector v;
public:
    Vector_container(std::initializer_list<int>);
    Vector_container(int s): v(s) {}
    ~Vector_container(){}

    double& operator[](int i) {return v[i];}
    int size() const {return v.size();}
};

void g() {
    Vector_container vc{1,2,3};
    use(vc);
}

class List_container: public Container{
    std::list<double> ld;
public:
    List_container(){}
    List_container(initializer_list<double> il){}
    ~List_container(){}
    double& operator[](int i);
    int size() const {return ld.size();}
};

double& List_container::operator[](int i) {
    for(auto& x: ld)
    {
        if (i == 0)
            return x;
        --i;
    }
}


//3.2.4
class Point{
public:
    int x, y;
};

class Shape{
public:
    virtual Point center() const=0;
    virtual void move(Point to) = 0;
    virtual void draw() const=0;
    virtual void rotate(int angle)=0;
    virtual ~Shape(){}
};

void rotate_all(vector<Shape*> &v, int angle) {
    for (auto p: v)
        p->rotate(angle);
}

class Circle: public Shape{
public:
    Circle(Point p, int rr);
    Point center() const {return x;}
    void move(Point to) {x = to; }
    void draw() const;
    void rotate(int){}

private:
    Point x;
    int r;
};

class Smiley: public Circle {
public:
    Smiley(Point p, int r): Circle{p,r}, mouth{nullptr}{}
    ~Smiley(){
        delete mouth;
        for(auto p: eyes)
            delete p;
    }
    void draw()const;
    void add_eye(Shape * p)
    {
        eyes.push_back(p);
    }

    void set_mouth(Shape* s);
    virtual void wink(int i);

    void move(Point to);
private:
    vector<Shape *> eyes;
    Shape *mouth;
};



template <typename T>
class Vector{
private:
    T* elem;
    int sz;
public:
    explicit Vector(int s);
    ~Vector(){delete[] elem; }

    T* begin(Vector<T> &);
    T* end(Vector<T> &);
    const T& operator[](int i);
    const T& operator[](int i) const;
    int size() const {
        return sz;
    }
};
template <typename T>
Vector<T>::Vector(int s) {
    if (s<0)
        ;
//        throw Negaive_size{};
    elem = new T[s];
    sz = s;
}

template <typename T>
const T& Vector<T>::operator[](int i)const {
    if (i < 0 || i >= size());
    return elem[i];
}

template<typename T>
const T &Vector<T>::operator[](int i) {
    return elem[i];
}

template <typename T>
T * Vector<T>::begin(Vector<T>& x) {
    return static_cast<int *>(&x[0]);
}

template <typename T>
T * Vector<T>::end(Vector<T>& x) {
    return x.begin() + x.size();
}

void f2(Vector<int> & vs) {
    for(auto s= vs.begin(vs); s != vs.end(vs); s++)
        cout << *s<<' ';
}

*/

//3.4.2  函数模板
template <typename Container, typename Value>
Value sum(const Container& c, Value v) {
    for(auto& x: c)
        v += x;
    return v;
}

void user(vector<int>& vi, std::list<double>& ld) {
    int x = sum(vi, 0);
    double d = sum(vi, 0.0);
    double dd = sum(ld, 0.0);
    cout << d <<' ' <<dd;
}


//3.4.3 函数对象
template <typename T>
class Less_than {
    const T val;
public:
    Less_than(const T &x) : val(x) {}
    bool operator()(const T &x) const { return x < val; }
};

Less_than<int> iti{42};;
Less_than<string> its{"Backus"};

void fct(int n, const string & s) {
    bool b1 = iti(n);
    bool b2 = its(s);
}

//3.4.4
void f(){
    cout << "end\n";
}

template <typename T, typename ...Tail>
void f(T head, Tail... tail) {
    cout << head<<' ';
    f(tail...);
}


//3.4.5
template <typename Key, typename Value>
class Map{

};
template <typename Value>
using String_map = Map<string, Value>;

String_map<int> m;

int main() {
//    3.2
//    complex a = complex(1,1);
//    complex b = complex(1,2);
//    a = a+=b;
//
//    vector<Point*> v;
//    Point * p = t();
vector<int> vi{1,2,3};
list<double>ld{1.9, 8.9};
user(vi, ld);

cout << endl;
f(1, 2.2, "hello");
f(0, 2, 'c', 0.1);




    return 0;
}
