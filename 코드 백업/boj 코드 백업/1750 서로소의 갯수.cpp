#include <stdio.h>
#include <algorithm>
using namespace std;

#define si(a) scanf("%d",&(a))

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
#define MAX_N 100001
#define MOD 10000003
int n;
int memo1[MAX_N];
int memo2[MAX_N];
int number[100];
int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		si(number[i]);
	}

	for (int iter = 0; iter < n; iter++) {
		int cur = number[iter];

		for (int i = 0; i < MAX_N; i++) {
			memo2[i] = memo1[i];
		}
		memo2[cur] += 1;
		
		for (int i = 1; i < MAX_N; i++) {
			if (memo1[i] == 0)continue;
			int val = gcd(i, cur);
			memo2[val] = (memo2[val] + memo1[i]) % MOD;
		} 

		for (int i = 0; i < MAX_N; i++) {
			memo1[i] = memo2[i];
			memo2[i] = 0;
		}
	}

	int ans = memo1[1];
	printf("%d\n", ans);

	return 0;
}