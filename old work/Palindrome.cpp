#include<iostream>

using namespace std;

int main()

{

    int n,i,j;

    char ch,ch1,ch2;

    cin>>n;

    for(i=0;i<n;i++)

    {

        for(j=1;j<n-i;j++)

            cout<<" ";

        ch1=ch='A'+i;

        ch2='A';

        for(;ch>='A';ch--)

            cout<<ch;

        for(;ch2<ch1;)

        {

            ch2++;

            cout<<ch2;

        }

        cout<<endl;

    }

    return 0;

}
