#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

#define LL long long
#define MP pair < int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define INF 1234567890
#define INFLL 12345678912345678
#define MAX_N 50000

int ans;
int train[MAX_N+1];
int n,k;
int psum[MAX_N + 10];
int memo[3][MAX_N+10];

int  main() {
	si(n);
	for (int i = 0; i < n; i++) {
		si(train[i]);
		psum[i + 1] = psum[i] + train[i];
	}
	si(k);

	memo[0][k] = psum[k] - psum[0];
	for (int i = k+1; i <= n; i++) {
		memo[0][i] = max(memo[0][i-1], psum[i] - psum[i - k]);
	}

	for (int i = k*2; i <= n; i++) {
		memo[1][i] = max(memo[1][i - 1], psum[i] - psum[i - k] + memo[0][i - k]);
	}
	for (int i = k * 3; i <= n; i++) {
		memo[2][i] = max(memo[2][i - 1], psum[i] - psum[i - k] + memo[1][i - k]);
	}

	ans = memo[2][n];
	printf("%d\n", memo[2][n]);
	return 0;
}











