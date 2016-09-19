#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>

using namespace std;

#define LL long long
#define MP pair < int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define INF 1234567890
#define INFLL 12345678912345678

#define MAX_N 1000
int memo[MAX_N + 1][MAX_N + 1];
int n, m;
int ans;
int  main() {
	si(n); si(m);
	getchar();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			memo[i][j] = getchar() - '0';
		}
		getchar();
	}
	for (int i = 0; i < MAX_N; i++) {
		ans = max(memo[i][0],ans);
		ans = max(memo[0][i], ans);
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (memo[i][j] == 0) continue;
			memo[i][j] = min(memo[i][j - 1], min(memo[i - 1][j], memo[i - 1][j - 1])) + 1;
			ans = max(memo[i][j], ans);
				
		}
	}

	printf("%d\n", ans*ans);
	return 0;
}












