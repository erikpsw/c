#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int>obj;

int main()
{

	int b = 1;
	int c ;
	while (b != 0)
	{
		cin >> c;
		b = c;
		obj.push_back(c);
	}
	obj.pop_back();
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		cout << obj[i] << ",";
	}
	sort(obj.begin(), obj.end());
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		cout << obj[i] << ",";
	}
	return 0;
}