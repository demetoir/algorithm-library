#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sc(a) scanf("%c",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define pii pair<int,int>
#define INF 2e9
#define LLINF ( (((LL)1) <<63)  -1)
#define AND &&
#define OR ||
#define FOR(i,s,e) for (int i = s; i<e; i++)
#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////

#define MAX_N 1000
char num[MAX_N];
int dp[40];
int cur[40];
int main() {
	int test = 1;
	for (int i = 0; i < 40; i++) {
		dp[i] = (1 << i) - 1;
	}
	dp[0] = 1;
	si(test);
	for (; test > 0; test--) {
		ss(num);
		int size = strlen(num);
		int ans = 0;
		memset(cur, 0, sizeof(cur));
		for (int i = 0; i < size - 1; i++) {
			if (cur[i] == num[i] - '0')continue;

			ans += dp[size - i - 1] + 1;
			cur[i + 1] = 1;
		}
		if (cur[size - 1] != num[size - 1] - '0') ans++;
		printf("%d\n", ans);

	}
	return 0;
}