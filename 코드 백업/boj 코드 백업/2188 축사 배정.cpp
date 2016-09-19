#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define MAX(a,b) (((a)>(b))? (a):(b))
#define MIN(a,b) (((a)<(b))? (a):(b))
#define ABS(a) (((a)<(0))? (-(a)):(a))
#define ll long long
#define si(a) scanf("%d",&a)

int n, m;
int s, t;
#define MAX_N 500+10
//int capacity[MAX_N][MAX_N];
int flow[MAX_N][MAX_N];
//int G[MAX_N][MAX_N];

int ford(int s, int t) {
	int maxflow = 0;
	//memset(flow, 0, sizeof(flow));

	while (1) {
		queue<int> Q;
		Q.push(s);
		
		vector<int> parent(MAX_N, -1);
		parent[s] = s;

		while (!Q.empty() && parent[t] == -1) {
			int cur = Q.front(); Q.pop();

			for (int next = 1; next <= n + m + 1; next++) {
				if (cur == next) continue;
				if (flow[cur][next] > 0 && parent[next] == -1) {
					Q.push(next);
					parent[next] = cur;
				}
			}
		}

		if (parent[t] == -1) break;

		int amount = 0x7fffffff;
		for (int p = t; p != s; p = parent[p]) {
			amount = MIN(amount, flow[parent[p]][p]);
		}

		for (int p = t; p != s; p = parent[p]) {
			flow[parent[p]][p] -= amount;
			flow[p][parent[p]] += amount;
		}
		maxflow += amount;
	}
	return maxflow;
}

int main() {
	si(n);
	si(m);
	s = 0;
	t = n + m + 1;

	for (int i = 1, number; i <= n; i++) {
		si(number);
		for (int j = 0, work; j < number; j++) {
			si(work);
			flow[i][work + n] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		flow[s][i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		flow[i + n][t] = 1;
	}


	int ans = ford(s, t);
	printf("%d\n", ans);
	return 0;
}
