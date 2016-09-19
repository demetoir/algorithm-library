#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 5000
#define si(a) scanf("%d",&(a))



vector <int> G[MAX_N + 1];
int n, m;
int ans, ansval = 1234567890;

int find(int start) {
	queue <int> q;
	vector <int> dist(MAX_N + 1,1234567890);
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i];
			if (dist[next] > dist[cur] + 1) {
				dist[next] = dist[cur] + 1;
				q.push(next);
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret += dist[i];
	return ret;

}

int main() {
	si(n);si(m);

	for (int i = 0,a,b; i < m; i++) {
		si(a); si(b);
		G[a].push_back(b);
		G[b].push_back(a);
	}


	for (int i = 1; i <= n; i++) {
		int val = find(i);
		if (val == ansval && i < ans) {
			ans = i;
		}
		else if (val < ansval) {
			ansval = val;
			ans = i;
		}
	}

	printf("%d\n", ans);
	return 0;
}