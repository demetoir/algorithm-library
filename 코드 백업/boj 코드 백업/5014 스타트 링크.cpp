#include <stdio.h>
#include <queue>

using namespace std;

#define MAX_N 1000000
#define si(a) scanf("%d",&(a));
#define INF 1234567890
int ans;
queue<int> Q;
int dist[MAX_N+1];
int f, s, g, u, d;


int main() {
	si(f);si(s);si(g);si(u);si(d);
	for (int i = 0; i < MAX_N+1; i++){

		dist[i] = INF;
	}
	dist[s] = 0;
	Q.push(s);
	while (!Q.empty()) {
		int cur = Q.front();
		int next;
		Q.pop();

		next = cur + u;
		if (1 <= next &&next <= f && dist[next] > dist[cur] +1) {
			Q.push(next);
			dist[next] = dist[cur] + 1;
		}

		next = cur - d;
		if (1 <= next &&next <= f && dist[next] > dist[cur] + 1) {
			Q.push(next);
			dist[next] = dist[cur] + 1;
		}
	}

	ans = dist[g];
	if (ans == INF)
		printf("use the stairs\n");
	else
		printf("%d\n",ans);
	return 0;
}