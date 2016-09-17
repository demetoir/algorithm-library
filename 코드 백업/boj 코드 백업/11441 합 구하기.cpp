#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define MP pair<int,int>
#define INF (1<<31 -1)
#define LLINF (((LL)1)<<63  -1)
#define AND &&
#define OR ||

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 100001
int tree[MAX_N];
int n;
int m;
int A[MAX_N];
LL ans;
int sum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i &-i);
	}
	return ret;
}
void update(int i, int diff) {
	while (i <= MAX_N) {
		tree[i] += diff;
		i += (i &-i);
	}
}
int main() {
	si(n);
	for (int i = 1; i <= n; i++) {
		si(A[i]);
		update(i, A[i]);
	}
	si(m);
	for (int i = 0,a,b; i < m; i++) {
		si(a);
		si(b);
		ans = sum(b) - sum(a - 1);
		printf("%d\n", ans);
	}

	return 0;
}




