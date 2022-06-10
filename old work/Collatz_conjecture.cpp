#include<stdio.h>
int main()
{
	while(1){ 
		int n;
		scanf("%d", &n);
		while (n != 1)
		{
			if (n % 2 == 1)
			{
				int sum = n * 3 + 1;
				printf("%d*3+1=%d\n", n,sum);
				n = sum;
			}
			else
			{
				int div = n / 2;
				printf("%d/2=%d\n", n, div);
				n = div;
			}
		}
	}
}

