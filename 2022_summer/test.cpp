#include<bits/stdc++.h>
using namespace std;


    int main()
{
	int v1,v0;
	double per;
	scanf("%d%d", &v1, &v0);
	if (v1 < (int)(v0 * 1.1)) {
		printf("OK");
	}
	else{
		per = (float)(v1 - v0) / (float)v0;
        per *= 100;
		if (v1 < (v0 * 1.5)) {
			printf("Exceed %.0lf%%. Ticket 200",per);
		}
		else if (v1 >= (v0 * 1.5)) {
			printf("Exceed %.0lf%%. License Revoked", per);
		}
	}

	return 0;
}

