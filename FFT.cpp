#include<iostream>
#include<vector>
#include<math.h>
#include<complex>
using namespace std;
const int pi = acos(-1);

void FFT(vector<complex<double>> a, int lim) {
    //复数数组的首地址，lim次数界
    if (lim == 1)return;
    vector<complex<double>> a0(lim >> 1), vector<complex<double>> a1(lim >> 1);
    //用vector动态分配内存
    for (int i = 0; i < lim; i += 2)
        a0.push_back(a[i]), a1[i >> 1] = a[i + 1];
    //分成奇数和偶数
    FFT(a0, lim >> 1);
    FFT(a1, lim >> 1);
    complex<double> wn{ cos(2.0 * pi / lim), sin(2.0 * pi / lim) };//主n次单位根
    complex<double> w{ 1,0 };//旋转因子
    for (int k = 0; k < (lim >> 1); ++k) {
        a[k] = a0[k] + w * a1[k];
        a[k + lim >> 1] = a0[k] - w * a1[k];
        w = w * wn;//使第k次时，w=wn^k
    }
}
int main() {
    return 0;
}