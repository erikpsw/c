#include <stdio.h>
using namespace std;

void print_subset(int n, int s) {
	for (int i = 0; i < n; i++) 
		if (s & (1 << i)) printf("%d", i);
		//1<<i代表某一位，如1000000等
		//只要非零都为真，&按位与，两1为1
		//按为1则输出的方式输出
	printf("\n");
}

int main() {
	int n = 9;
	for (int i = 0; i < (1 << n); i++)
		//1<<n<=>2^n,即为子集个数
		//从1-2^n的每一个二进制数代表子集，1代表在子集内
		print_subset(n,i);
}