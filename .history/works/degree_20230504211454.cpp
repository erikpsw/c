#include<bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846

class deg{
public: 
    deg(int d,int m):d(d),m(m){};
    friend deg operator +(deg a, deg b) {return a.m+b.m>=60?deg(a.d+b.d+1,a.m+b.m-60):deg(a.d+b.d,a.m+b.m);};
    friend deg operator -(deg a, deg b) {return a.m-b.m<0?deg(a.d-b.d-1,60+a.m-b.m):deg(a.d-b.d,a.m-b.m);};
    friend void print(deg a) {cout<<a.d<<"°"<<a.m<<"'"<<endl;};
    double todouble() {return d+(m/60.);};
private:
    int d,m;
};
deg todeg(double a) {return deg(floor(a),round((a-floor(a))*60));};

int main(){
    double d=0.00333;
    deg p1=deg(271,10);
    deg p1p=deg(86,14);
    deg p2=deg(257,11);
    deg p2p=deg(71,10);
    print(p1-p2);
    print(p1p-p2p);
    double p=(p1-p2+p1p-p2p).todouble()/4;
    print(todeg(p));
    cout<<sin(p*M_PI /180)<<endl;
    cout<<"k=2"<<(d*sin(p*M_PI /180))/2<<endl;
    cout<<"k=3"<<(d*sin(p*M_PI /180))/3<<endl;
    double std=435.8;
    cout<<"E:"<<100*(abs()/435.8)<<endl;
}