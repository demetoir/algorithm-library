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
#define sS(a) scanf("%s",a)
#define INF 1234567890
#define INFLL 12345678912345678
#define MAX_N 1000

vector <int> G[MAX_N + 1];
int n, m;
int check[MAX_N+1];
int ans;
void dfs(int cur) {
	if (check[cur] == 1)return;
	check[cur] = 1;
	for (int i = 0; i < G[cur].size(); i++) {
		dfs(G[cur][i]);
	}
	return;
}
int  main() {
	si(n); si(m);

	for (int i = 0,a,b; i < m; i++) {
		si(a); si(b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) {
			dfs(i);
			ans += 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}











