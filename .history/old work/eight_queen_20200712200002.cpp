#include<iostream>
using namespace std;


const int num=10;
int ok[num*3][num*3];
int solution[num];
int cur_row, cur_column,tot=0;
int search(int cur_row)
{
	if (cur_row == num)
	{
		tot++;
		for (int i = 0; i < sizeof(solution) / sizeof(solution[0]); i++)

			cout << solution[i] << " ";
		cout << endl;

	}
	else for (int cur_column = 0; cur_column < num; cur_column++) {
		if (!ok[0][cur_column] && !ok[1][cur_column + cur_row] && !ok[2][cur_row - cur_column + num])
		{
			ok[0][cur_column] = ok[1][cur_column + cur_row] = ok[2][cur_row -cur_column + num] = 1;
			solution[cur_row] = cur_column+1;
			search(cur_row + 1);
			ok[0][cur_column] = ok[1][cur_column + cur_row] = ok[2][ cur_row - cur_column  + num] = 0;
		}

	}
	return tot;
}
int main()
{	
	cout << search(0);
}