#include<iostream>
using namespace std;

int price[] = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
int max_cut[12];
int plan[11];
const int len = sizeof(price) / sizeof(price[0]);

void print_cut_rod_solution(int cur_len)
{
	while(cur_len > 0)
	{
		cout << plan[cur_len]<<" ";
		cur_len = cur_len - plan[cur_len];
	}
}

int main()
{
	for (int i = 1; i < len; i++)
	{
		int cur_price = INT_MIN;
		int place = 0;
		for (int t = 0; t < i; t++)
		{
			if (cur_price < (price[t + 1] + max_cut[i - t - 1]))
			{
				cur_price = (price[t + 1] + max_cut[i - t - 1]);
				place = t + 1;
			}
		}
		plan[i] = place;
		max_cut[i] = cur_price;
	}
	for (int i = 0; i < len; i++)
		cout << max_cut[i] << " ";
	cout << endl;
	for (int i = 0; i < len; i++)
		cout << plan[i] << " ";
	cout << endl;
	print_cut_rod_solution(8);
}
