#include <stdio.h>
using namespace std;
//A为数字数组
void print_permutation(int n, int* A, int cur=0) {
	if (cur == n) {
		for (int i = 0; i < n; i++) printf("%d ", A[i]);
		printf("\n");
	}
	else for (int i = 1; i <= n; i++) {//从1-n里遍历
		int ok = 1;
		for (int j = 0; j < cur; j++)
			if (A[j] == i)ok = 0;//检查是否重复
		if (ok) {
			A[cur] = i;
			print_permutation(n, A, cur+1);//只能用+1
		}
	}
}

int main() {
	int A [1000];
	print_permutation(5,A);
}