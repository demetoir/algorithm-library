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

#define MAX_V 20001
int v,e,k;

vector<pii>G[MAX_V];
vector<int>dist;
void spf(int start) {
	queue<int>q;
	q.push(start);
	dist = vector<int>(MAX_V, INF);
	dist[start] = 0;
	vector<bool> isinqueue(MAX_V);
	isinqueue[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		isinqueue[cur] = false;

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				if (isinqueue[next] == false) {
					isinqueue[next] = true;
					q.push(next);
				}
			}
		}
	}
}
int main() {
	si(v);si(e);
	si(k);
	for (int i = 0,a,b,c; i < e; i++) {
		si(a);si(b);si(c);
		G[a].push_back(pii(b, c));
	}

	spf(k);
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}