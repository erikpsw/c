#include<bits/stdc++.h>
using namespace std;

int a0[]={2,3};  //2x+3

int calc(int *a,int x,int pos){
    if (pos==1){
        return a[0]*x+a[1];
    }
    else{
        return a[pos-1]*calc(a,x,pos-1)+a[pos];
    }
}


int main()
{
    cout<<calc(a0,2,1);
}