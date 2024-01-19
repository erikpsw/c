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
    deg p1=deg(271,10);
    deg p1p=deg(86,14);
    deg p2=deg(251,11);
    deg p2p=deg(71,10);
    print(p1-p2);
    print(p1p-p2p);
    print(todeg((deg(277,45)-deg(239,29)+deg(97,49)-deg(59,30)).todouble()/4));
    cout<<sin(M_PI/4)<<endl;
}