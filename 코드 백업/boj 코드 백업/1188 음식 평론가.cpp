#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define si(a) scanf("%d",&(a))

int n, m;
int seat[50];
int vip[50];
int fib[50];
int ans;
int bar[10001];
int main() {
	si(n);
	si(m);
	ans = 0;

	for (int i = 1; i < n*m; i++) {
		if (i%n == 0 && i%m > 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}
