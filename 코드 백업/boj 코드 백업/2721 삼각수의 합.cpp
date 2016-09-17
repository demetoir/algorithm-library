#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sf(a) scanf("%f",&(a))
#define LL long long
#define MOD 1000000000
#define PRIME_SIZE 8
#define MAX_N 5000

int memo[MAX_N + 1];
int n;
int T;
int ans;

int main() {
	int testcase = 0;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		si(n);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			T = (1 + i)*(i+2) / 2;
			ans += i*(T);
		}
		printf("%d\n", ans);
	}

	return 0;
}