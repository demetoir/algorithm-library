#include <stdio.h>
#include <algorithm>

#define si(a) scanf("%d",&(a))
int n, k;
#define MOD 10007
#define MAX_N 1000
int memo[MAX_N + 1][MAX_N + 1];

int main() {
	si(n);
	si(k);
	memo[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		memo[i][0] = memo[i][i] = 1;
		for (int j = 1; j < i; j++) {
			memo[i][j] = memo[i - 1][j] + memo[i - 1][j - 1];
		}
	}
	int ans =memo[n][k];
	printf("%d\n", ans);



	return 0;
}

