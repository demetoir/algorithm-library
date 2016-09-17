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

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 20000
vector <int> color;
vector < int> G[MAX_N + 1];
int ans;
int v, e;
bool dfs(int cur, int c) {
	if (color[cur] != -1) {
		return color[cur] == c;
	}
	color[cur] = c;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		if (dfs(next, 1 - c) == false)
			return false;
	}
	return true;
}



int  main() {
	int testcase;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		for (int i = 0; i <= MAX_N; i++) {
			G[i].clear();
		}
		color = vector<int>(MAX_N + 1, -1);

		si(v); si(e);
		for (int i = 0, a, b; i < e; i++) {
			si(a);si(b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		ans = 1;
		for (int i = 1; i <= v; i++) {
			if (color[i] == -1 && dfs(i, 1) == false)
				ans = 0;
		}
		if (ans)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}











