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
#define LLINF ( (((LL)1) <<62)  -1)
#define AND &&
#define OR ||

#define FOR(i,s,e) for (int i = s; i<e; i++)
//////////////////////////////////////////////////////////////////////////////////


#define MAX_N 501
#define MAX_M 6001

char str[MAX_N];
int n,m;
int ans = 0;
vector <MP> G[MAX_N];

int parent[MAX_N];
int dist[MAX_N];

bool find() {
	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;
	memset(parent, 0, sizeof(dist));
	bool update = true;

	for(int iter = 0; iter<n; iter++){
		update = false;
		for (int cur = 1; cur <= n; cur++) {
			for (int j = 0; j < G[cur].size(); j++) {
				int next = G[cur][j].first;
				int cost = G[cur][j].second;

				if (dist[next] > dist[cur] + cost) {
					dist[next] = dist[cur] + cost;
					update = true;
					parent[next] = cur;
				}
			}
		}
	}
	if (update) return false;
	
	return true;
}



int main() {
	si(n);
	si(m);
	for (int i = 0,a,b,c; i < m; i++) {
		si(a);
		si(b);
		si(c);
		G[a].push_back(MP(b, c));
	}

	if (find() == false) printf("-1\n");
	else {
		
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF)dist[i] = -1;
			printf("%d\n", dist[i]);
		}
	}

	
	return 0; 
}

