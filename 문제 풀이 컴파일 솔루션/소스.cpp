//밑에 매크로 사용법 있음
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
#include <limits>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
typedef long long LL;

#define INF 2e9
#define LLINF ( (LL)1e18 )

#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sll(a) scanf("%lld",&(a))
#define sc(a) scanf("%c",&(a))
#define ss(a) scanf("%s",a)
#define pii pair<int,int>
#define all(a) (a).begin(),(a).end()
////////////////////////////////////////////////////////////////////////
#define MAX_N 1001
int n;
int seq[MAX_N];
int dp[MAX_N];
int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		si(seq[i]);
	}

	dp[0] = seq[0];
	int size = 1;
	for (int i = 1; i < n; i++) {
		if (dp[size - 1] < seq[i]) {
			dp[size] = seq[i];
			size++;
		}
		else {
			dp[lower_bound(dp, dp + size, seq[i]) - dp] = seq[i];
		}
	}
	int ans = size;
	printf("%d\n",ans);
	return 0;
}