#include <stdio.h>
#include <algorithm>
using namespace std;

#define si(a) scanf("%d",&(a))
#define MAX_N 1001

int n;
int memo[MAX_N];
int fish[MAX_N];
int ans;

int main() {
	si(n);
	for (int i = 0,val; i < n; i++) {
		si(fish[i]);
	}

	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= n; k++) {
			if (k - i < 0) continue;
			memo[k] = max(memo[k], memo[k - i] + fish[i-1]);
		}
	}

	printf("%d\n", memo[n]);


	return 0;
}

