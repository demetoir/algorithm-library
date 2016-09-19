#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define si(a) scanf("%d",&(a))

int n,m;
int seat[50];
int vip[50];
int fib[50];
int ans;

int main() {
	si(n);
	si(m);
	fib[0] = 1;
	fib[1] = 1;
	ans = 1;
	for (int i = 2; i <= 40; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}

	vip[0] = 0;
	for (int i = 1, val; i < m+1; i++) {
		si(vip[i]);
	}
	vip[m + 1] = n+1;

	for (int i = 0 ,val; i < m +1; i++) {
		val = vip[i + 1] - vip[i] - 1;
		ans *= fib[val];
	}

	printf("%d\n", ans);
	return 0;
}
