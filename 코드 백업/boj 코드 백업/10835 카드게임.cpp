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
#define MAX_N 2010
int memo[MAX_N][MAX_N];
int A[MAX_N];
int B[MAX_N];
int n;
int ans;
int main() {
	si(n);
	for (int i = 0; i < n; i++)si(A[n-i]);
	for (int i = 0; i < n; i++)si(B[n-i]);

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			memo[i][j] = -INF;
		}
	}

	for (int i = 0; i <= n; i++) {
		memo[i][0] = 0;
		memo[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j<=n; j++) {
			memo[i][j] = max(memo[i - 1][j], memo[i][j]);
			memo[i][j] = max(memo[i-1][j-1], memo[i][j]);

			if (A[i] > B[j]) {
				memo[i][j] = max(memo[i][j-1]+ B[j],memo[i][j]);
			}
		}
	}
	ans = memo[n][n];
	
	printf("%d\n", ans);
	return 0;
}




