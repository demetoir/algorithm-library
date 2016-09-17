#include <stdio.h>
#include <math.h>

#define si(a) scanf("%d",&(a))
using namespace std;
#define MAX_N 20
#define LL long long
LL memo[MAX_N + 1][MAX_N + 1];
int n, m;
LL gcd(LL a, LL b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
int main() {
	memo[0][0] = 1;
	for (int i = 1; i <= MAX_N; i++) {
		for (int j = 1; j <= i; j++) {
			memo[i][j] = (i-1)*memo[i - 1][j] + memo[i - 1][j - 1];
		}
	}

	si(n); si(m);
	LL a=0, b=0;

	for (int i = 1; i <= n; i++) {
		if (i <= m)
			a += memo[n][i];
		b += memo[n][i];
	}

	LL g = gcd(a, b);
	printf("%lld/%lld\n", a/g, b/g);
	return 0;
}

