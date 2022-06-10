#include<bits/stdc++.h>
using namespace std;

int main(){
	int line1[] = { 0,2,0 };
	int line2[] = { 0,1,0 };
	int line3[] = { 3,0,0 };
	int *pLine[] = { line1,line2,line3 };//数组名为指针(pointer)
	cout << "Matrix test" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << pLine[i][j] << " ";//pLine[1]为line2的首地址
		cout << endl;
	}//构造后就不能再增加元素
	int** narr = new int* [3];//第一维,新建了一个指针数组
	for (int i = 0; i < 3; i++) {
		narr[i] = new int[4];//第二维
	}
	int n = 0;
	for (int p = 0; p <3 ; ++p) {
		int t = 0;
		for (int y = 0; y < 4 ; ++y) {
			if (t == 3)narr[n][t] = 0;
			else {
				narr[n][t] = pLine[n][t];
			}
			t = t + 1;
		}
		n = n + 1;
	}
	cout << "New array" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++)
			cout << narr[i][j] << " ";//pLine[1]为line2的首地址
		cout << endl;
	}
}