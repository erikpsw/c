#include<iostream>
using namespace std;

//有多大
const int num=10;
int ok[2][num];
int solution[num];
int cur_row, cur_column,tot=0;
int search(int cur_row)
{
	if (cur_row == num)
	{
		tot++;
		for (int i = 0; i < sizeof(solution) / sizeof(solution[0]); i++)
		// 递归边界
			cout << solution[i] << " ";
		cout << endl;

	}
	else for (int cur_column = 0; cur_column < num; cur_column++) {
		if (!ok[0][cur_column] && !ok[1][cur_column + cur_row] && !ok[2][cur_row - cur_column + num])//判断上一级的列和两对角线
		{
			ok[0][cur_column] = ok[1][cur_column + cur_row] = ok[2][cur_row -cur_column + num] = 1;//表示放上了
			solution[cur_row] = cur_column+1;//注意从0开始
			search(cur_row + 1);
			ok[0][cur_column] = ok[1][cur_column + cur_row] = ok[2][ cur_row - cur_column  + num] = 0;//存在辅助的全局变量，重新开始
		}

	}
	return tot;
}
int main()
{	
	cout << search(0);
}