#include <stdio.h>

#define si(a) scanf("%d",&(a))
#define LL long long
#define MOD 1000000000
int n;
int ans = 0;
int a1 = 0, a2 = 1,a3;
int main() {
	si(n);
	for (int i = 0; i < n-2; i++) {
		a3 = ((LL)(i + 2)*(LL)(a2 + a1))%MOD;
		a1 = a2;
		a2 = a3;	
	}

	if (n == 1) ans = 0;
	else if (n == 2) ans = 1;
	else ans = a3;

	printf("%d\n",ans);
	return 0;
}