
//Fibonacci数列的第一项为0，第二项为1，后续的每一项是前两项的和
//该数列的前两项的比例趋于一个常量：1.168...，成为黄金分割 数列形如：0 1 1 2 3 5 8 13 21 34...
#include <iostream>
using namespace std;
long int Leo(long int n);
int main()
{
    long n;
    cin>>n;//求Fibonacci数列的第n项
    cout<<Leo(n)<<endl;
    return 0;
}
long int Leo(long int n)
{
  if(n==0 || n==1)
    return n;
  else
    return Leo(n-1)+Leo(n-2);
}