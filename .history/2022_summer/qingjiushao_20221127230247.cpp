#include<bits/stdc++.h>
using namespace std;



int calc(int *a,int x,int pos){
    if (pos==1){
        return a[0]*x+a[1];
    }
    else{
        return x*calc(a,x,pos-1)+a[pos];
    }
}


int main()
{
    int a0[]={3,2,1};  //2x+3
    int len=sizeof(a0)/sizeof(a0[0]);
    cout<<calc(a0,1,2);
}