#include<bits/stdc++.h>
using namespace std;

class deg{
public: 
    deg(int d,int m):d(d),m(m){};
    friend deg operator +(deg a, deg b) {return a.m+b.m>=60?deg(a.d+b.d+1,a.m+b.m-60):deg(a.d+b.d,a.m+b.m);};
    friend deg operator -(deg a, deg b) {return a.m-b.m<0?deg(a.d-b.d-1,60+a.m-b.m):deg(a.d-b.d,a.m-b.m);};
    friend void print(deg a) {cout<<a.d<<"°"<<a.m<<"'";};
    double todeg() {return d+(m/60.);};
private:
    int d,m;
};

int main(){

    cout<<deg(65,2).todeg()<<endl;
    print((deg(277,45)-deg(239,29)+deg(97,49)-deg(59,30)).todeg()/4);
}