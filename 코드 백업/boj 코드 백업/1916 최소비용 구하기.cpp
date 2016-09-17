#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 1000
#define si(a) scanf("%d",&(a))
#define MP pair<int,int>
#define LL long long
#define INF 9876543217654321

vector <MP> G[MAX_N + 1];
int n, m;
LL ans;
int start, dest;
LL find() {
	queue <int> q;
	vector <LL> dist(MAX_N + 1, INF);
	dist[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int cost = G[cur][i].second;

			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				q.push(next);
			}
		}
	}
	LL ret = dist[dest];

	return ret;

}

int main() {
	si(n); si(m);

	for (int i = 0, a, b,c; i < m; i++) {
		si(a); si(b); si(c);
		G[a].push_back(MP(b,c));
	}
	si(start); si(dest);

	ans = find();

	printf("%lld\n", ans);
	return 0;
}