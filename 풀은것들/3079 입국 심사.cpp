#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <limits>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <functional>

using namespace std;
typedef long long LL;

#define INF 2e9
#define LLINF ((LL)1e18)
#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sll(a) scanf("%lld",&(a))
#define sc(a) scanf("%c",&(a))
#define ss(a) scanf("%s",a)
#define MP pair<int,int>
//////////////////////////////////////////////////////////////////////////////////////////
#define MAX_N 100001

int n, m;
int T[MAX_N];
LL ans;
bool find(LL time) {
	LL ret = 0;
	for (int i = 0; i < n; i++) {
		ret += (time / T[i]);
	}
	if (ret >= m) {
		return true;
	}
	return false;
}

int main() {
	si(n);
	si(m);
	for (int i = 0; i < n; i++) si(T[i]);

	ans = LLINF;
	LL lo = 0, hi = LLINF;
	while (lo <= hi) {
		LL mid = (lo + hi) / 2;
		//printf("##%lld\n", mid);
		if (find(mid)) {
			ans = min(ans, mid);
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	printf("%lld\n", ans);
	return 0;
}



