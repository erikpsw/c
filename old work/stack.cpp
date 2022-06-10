#include<stack>
#include<iostream>
using namespace std;
stack <int> a ;

int main()
{	
	a.push(1);
	a.push(2);
	a.push(3);
	cout << a.top() << endl;
	cout << a.size() << endl;
	cout << a.empty() << endl;
	a.pop();
	cout << a.top() << endl;
}