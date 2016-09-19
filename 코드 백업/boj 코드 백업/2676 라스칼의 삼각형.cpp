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


int ans[1000];
int n,m;


int main() {
	int testcase = 0;
	si(testcase);
	for (int i = 0; i < testcase; i++) {
		si(n); si(m);
		if (n == 0 || m == 0 || m > n) {
			printf("1\n");
			continue;
		}
		int ans = (n - m) *m +1;
		printf("%d\n", ans);

	}
	return 0;
}