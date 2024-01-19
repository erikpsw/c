#include<bits/stdc++.h>
using namespace std;

class deg{
public: double d,m;
    deg(double d,double m):d(d),m(m){};
    friend bool operator +(deg a, deg b);
};

int main(){
    deg(65,2);
}