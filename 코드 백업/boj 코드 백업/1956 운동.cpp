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

////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1000


vector <MP> G[MAX_N];
int v, e;
int ans;
int find(int start) {
	queue<int> q;
	q.push(start);
	vector<int>dist(v + 1, INF);
	dist[start] = 0;
	int ret = INF;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				q.push(next);
			}
			if (next == start) {
				ret = min(dist[cur] + cost, ret);
			}
		}
	}
	return ret;

}
int  main() {
	si(v); si(e);
	for (int i = 0,a,b,c; i < e; i++) {
		si(a); si(b); si(c);
		G[a].push_back(MP(b, c));
	}
	ans = INF;
	for (int i = 1; i <= v; i++) {
		ans = min(ans, find(i));
	}
	if (ans == INF) ans = -1;

	printf("%d\n", ans);
	return 0;

}











