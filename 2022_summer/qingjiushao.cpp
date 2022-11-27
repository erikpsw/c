#include<bits/stdc++.h>
using namespace std;

int calc(float *a,float x,int pos){
    if (pos==1){
        return a[0]*x+a[1];
    }
    else{
        return x*calc(a,x,pos-1)+a[pos];
    }
}

int main()
{
    float a0[]={3,2,1};  //3x^2+2x+1
    float x=2;
    int len=sizeof(a0)/sizeof(a0[0])-1;
    cout<<calc(a0,x,len);
}