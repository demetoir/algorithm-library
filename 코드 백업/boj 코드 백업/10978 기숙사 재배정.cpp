#include <stdio.h>

#define si(a) scanf("%d",&(a))
#define LL long long
#define MOD 1000000000
LL memo[100];
int n;
LL ans = 0;
LL a1 = 0, a2 = 1, a3;

int main() {
	memo[1] = 0;
	memo[2] = 1;

	for (int i = 0; i < 50; i++) {
		a3 = (LL)(i + 2)*(LL)(a2 + a1);
		memo[i + 3] = a3;
		a1 = a2;
		a2 = a3;
	}

	int testcase;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		si(n);
		ans = memo[n];
		printf("%lld\n", ans);

	}

	return 0;
}