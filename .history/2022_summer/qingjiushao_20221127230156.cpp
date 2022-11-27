#include<bits/stdc++.h>
using namespace std;

int a0[]={3,2,1};  //2x+3

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
    cout<<calc(a0,1,2);
}