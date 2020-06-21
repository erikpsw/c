#include <iostream>
using namespace std;
template<typename T>
void Quick_sort(T List[], int l, int r)
{
	if (l >= r)return;
	int i = l, j = r;
	T key = List[l];
//注意顺序，i/j移动时，key始终静止
	while (i != j) {
		while (i < j && List[j] >= key)j--;
		swap(List[i], List[j]);
		while (i < j && List[i] <= key)i++;
		swap(List[i], List[j]);
	}
	Quick_sort(List, l, --j);
	Quick_sort(List, ++i, r);
}
int main()
{
	int List[6] = { 6,2,7,3,9,8 };
	Quick_sort(List, 0, 5);
	for (auto i : List)
		cout << i << endl;
}