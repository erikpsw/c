#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

struct Complex
{
    double r, i;
    Complex() { r = 0, i = 0; }; //默认构造函数
    Complex(double real, double imag) :r(real), i(imag) {}
    //初始化列表，用real初始化r，imag初始化i
};

//重载运算符
Complex operator + (Complex a, Complex b) {
    return Complex(a.r + b.r, a.i + b.i);
}

Complex operator - (Complex a, Complex b) {
    return Complex(a.r - b.r, a.i - b.i);
}

Complex operator * (Complex a, Complex b) {
    return Complex(a.r * b.r - a.i * b.i, a.i * b.r + a.r * b.i);;
}
