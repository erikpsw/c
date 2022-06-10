#include <iostream>
using namespace std;
//注意顺序，i/j移动时，key始终静止;
void Insertsort(int List[], int l, int r)
{
	for (int i = l + 1; i <= r; ++i)
	{
		for (int j = i; j > 0 && List[j] < List[j - 1]; --j) {
			swap(List[j], List[j - 1]);
		}
	}
}


void Quick_sort(int List[], int l, int r){
	if (l >= r)return;
	if (r - l + 1 < 10) {
		Insertsort(List, l, r);
		return;
	}
	int i = l, j = r, pivot = rand() % (r - l + 1) + l;
//随机选取key，pivot为基准点
	swap(List[i], List[pivot]);
    int key = List[i];
	while (i != j)
	{
		while (i < j && List[j] >= key)j--;
		while (i < j && List[i] <= key)i++;
		swap(List[i], (i == j) ? List[l] : List[j]);
		//l为基准点，若i==j，则i，j相遇，就可以交换l
	}
	Quick_sort(List, l, --j);
	Quick_sort(List, ++i, r);
}
int main()
{
	int List[100];
	for (int i=0;i<100;i++)
	{
		List[i] = rand() % 200;
	}
	Quick_sort(List, 0, 99);
	for (auto i : List)
		cout << i << endl;
}
