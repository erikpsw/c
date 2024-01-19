#include<bits/stdc++.h>
using namespace std;

class deg{
public: double d,m;
    deg(double d,double m):d(d),m(m){};
    friend deg operator +(deg a, deg b){a.m+b.m>=60?return deg()};
};

int main(){
    deg(65,2);
}