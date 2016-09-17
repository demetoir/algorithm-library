#include <stdio.h>
#include <algorithm>
using namespace std;
#define si(a) scanf("%d",&(a))
#define MAX_N 1001
int n;
int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}


int memo[1001];

int main() {
	int testcase;
	si(testcase);

	for (int i = 1; i < MAX_N; i++) {
		memo[i] = memo[i - 1];
		if (gcd(i, i) == 1) memo[i]++;
		for (int j = 0,x,y; j < i; j++) {
			x = i;
			y = j;
			if (gcd(x, y) == 1) memo[i]++;
			x = j;
			y = i;
			if (gcd(x, y) == 1) memo[i]++;
		}
	}

	for (int test = 0; test < testcase; test++) {
		si(n);
		printf("%d\n", memo[n]);
	}
	return 0;
}


