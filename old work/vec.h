#include<bits/stdc++.h>
using namespace std;

typedef vector<double> vec;
vec operator-(const vec& x, const vec& y)
{
    assert(x.size() == y.size());
    vec tmp;
    for (size_t i = 0; i < x.size(); ++i)
        tmp.push_back(x[i] - y[i]);
    return tmp;
}
vec operator+(const vec& x, const vec& y)
{
    assert(x.size() == y.size());
    vec tmp;
    for (size_t i = 0; i < x.size(); ++i)
        tmp.push_back(x[i] + y[i]);
    return tmp;
}
double operator*(const vec& x, const vec& y)
{
    assert(x.size() == y.size());
    double sum = 0.;
    for (size_t i = 0; i < x.size(); ++i)
        sum += x[i] * y[i];
    return sum;
}

double operator^(const vec& x, const vec& y)
{
    assert(x.size() == y.size() && x.size() == 2);
    return (double)((x[0] * y[1]) - (x[1] * y[0]));
}
double norm(const vec& x)
{
    double val = 0.;
    for (auto elem : x)
        val += elem * elem;
    return sqrt(val);
}

#define PI 3.14159265358979323846
double toDegree(double val)
{
    return val * 180 / PI;
}

double angle(const vec& x, const vec& y)
{
    return toDegree(acos(x * y / (norm(x) * norm(y))));
}
double distance(const vec& x0, const vec& x1, const vec& x2)
{
    return ((x1 - x0) ^ (x2 - x0)) / norm(x1 - x2);
}
void print(const vec& a) {
    cout << "(";
    for (size_t i = 0; i < a.size() - 1; ++i) {
        cout << a[i] << ',';
    }
    cout << a[a.size() - 1] << ")";
}

class point {
public:
    bool visit = false;
    point(double x = 0, double y = 0) : x(x), y(y) {//构造函数
    }
    point(const point& p) {
        x = p.x; y = p.y;
    }
    bool isVisit() { return visit; }
    double getX() { return x; }
    double getY() { return y; }
    friend double dis(const point& a, const point& b);
    friend void print(const point& c);
    friend bool toleft(const point& a, const point& b, const point& c);
    friend double area(const point& a, const point& b, const point& c);
    friend bool inPolygon(vector<point> arr, const point& a);
    friend bool inTriangle(const point& a, const point& b, const point& c, const point& d);
    friend bool operator ==(const point& a, const point& b);
    friend bool operator !=(const point& a, const point& b);
private:
    double x, y;
};

double dis(const point& a, const point& b) {
    double x = (double)b.x - (double)a.x;
    double y = (double)b.y - (double)a.y;
    return static_cast<double>(sqrt(x * x + y * y));
}

void print(const point& c) {
    cout << "(" << c.x << "," << c.y << ")";
}

//计算有向面积
double area(const point& a, const point& b, const point& c) {
    double area2;
    area2=(a.x * b.y - a.y * b.x
        + b.x * c.y - b.y * c.x
        + c.x * a.y - c.y *a.x);
    return 0.5 * area2;
}
bool toleft(const point& a, const point& b, const point& c) {
    return area(a, b, c) > 0;
}

bool inTriangle(const point& a, const point& b, const point& c, const point& d){
    return toleft(a, b, d) & toleft(b, c, d) & toleft(c, a, d);
}

bool inPolygon(vector<point> arr, const point& a) {
    bool ok = 1;
    for (unsigned int i = 0; i < arr.size()-1; ++i) {
        ok = ok & toleft(arr[i], arr[i + 1], a);
    }
    return ok;
}

bool operator ==(const point& a, const point& b) {
    return (a.x == b.x) & (a.y == b.y);
}

bool operator !=(const point& a, const point& b) {
    return (a.x != b.x) | (a.y != b.y);
}
