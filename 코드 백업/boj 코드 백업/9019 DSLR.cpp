#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
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

#define MAX_N 10001
#define MAX_M 6001

int n, m;
int a, b;
int dist[MAX_N];
int parent[MAX_N];

void find() {
	queue<int>q;
	q.push(a);
	for (int i = 0; i < MAX_N; i++) {
		dist[i] = INF;
		parent[0] = 0;
	}
	dist[a] = 0;
	parent[a] = a;
	int next;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		next = (cur * 2) % 10000;
		if (dist[next] > dist[cur]+1) {
			parent[next] = cur;
			dist[next] = dist[cur]+1;
			q.push(next);
		}

		next = (cur - 1 + 10000) % 10000;
		if (dist[next] > dist[cur] + 1) {
			parent[next] = cur;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}

		next = ((cur%1000)*10  + cur / 1000) % 10000;
		if (dist[next] > dist[cur] + 1) {
			parent[next] = cur;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
		
		next = ((cur%10)*1000 + cur/10) % 10000;
		if (dist[next] > dist[cur] + 1) {
			parent[next] = cur;
			dist[next] = dist[cur] + 1;
			q.push(next);
		}
	}


}

int ans[MAX_N];
int main() {
	int test;
	si(test);
	for (; test > 0; test--) {
		si(a);si(b);
		memset(ans, 0, sizeof(ans));
		find();

		int index = 0;
		for (int cur = b; cur != parent[cur]; cur = parent[cur],index++) {
			int pre = parent[cur];
			if (cur == (pre * 2) % 10000) {
				ans[index] = 'D';
			}
			else if(cur == (pre - 1 + 10000) % 10000) {
				ans[index] = 'S';
			}
			else if (cur == ((pre % 1000) * 10 + pre / 1000) % 10000) {
				ans[index] = 'L';
			}
			else if (cur == ((pre % 10) * 1000 + pre / 10) % 10000) {
				ans[index] = 'R';
			}
		}
		for (int i = index - 1; i >= 0; i--)
			printf("%c", ans[i]);
		printf("\n");
	}

	return 0;
}

