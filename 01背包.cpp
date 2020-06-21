#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int V_num = 8;
	int N_num = 4;
	int F[10][10];
	int V[5] = { 0,2, 3, 4, 5 };
	int C[5] = { 0,3,4,5,6 };
	for (int i = 0; i < 10; i++) F[0][i] = 0;
	for (int i = 1; i <= N_num; ++i)
	{
		for (int j = 0; j <= V_num; ++j)
		{
			F[i][j] = (i == 1 ? 0 : F[i - 1][j]);
			if (V[i] <= j)
				F[i][j] = max(F[i][j], F[i - 1][j - V[i]] + C[i]);
			cout << "F" << " " << i << " " << j << " :" << F[i][j] << endl;

		}
	}
}
