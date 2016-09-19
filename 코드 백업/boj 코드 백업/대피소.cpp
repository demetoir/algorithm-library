#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <string.h>

using namespace std;

vector<int> iv;
vector<int>::iterator iit;
vector<double> dv;
priority_queue <int> PQ;
queue <int>  Q;
map<int, string> istrmap;
map <long long, int>iimap;
struct mp {
	int a, b;
};
#define ABS(a)(((a) < (0))?-(a):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int n, m, K;
vector< vector<pair<int, int> > >  G;
int dist[1000001];
///////////////1000000000
#define MAXDIS 1234567890;
vector <int > start;
long long ans1 = 0;
long long ans2 = 0;
int dir[1000001];
vector< vector<int> >  dirG;
void init() {
	G.clear();
	dirG.clear();
	for (int i = 0; i < n + 1; i++) {
		dist[i] = MAXDIS;
		dir[i] = 0;
		G.push_back(vector<pair<int, int> >());
		dirG.push_back(vector<int>());
	}
	start.clear();
	ans1 = 0;
	ans2 = 0;
}


void f() {
	priority_queue < pair<int, int>, vector< pair <int, int> >, greater<pair<int, int> > > PQ;

	for (int i = 0; i< start.size(); i++) {
		int a = start[i], b = 0;
		PQ.push(make_pair(b, a));
		dist[a] = 0;
		dir[a] = a;
	}
	while (!PQ.empty()) {
		int cur, total;
		total = PQ.top().first;
		cur = PQ.top().second;
		PQ.pop();
		//printf("## %d %d\n", cur, total);
		if (dist[cur] < total) { continue; }
		for (int i = 0; i < G[cur].size(); i++) {
			int next = G[cur][i].first;
			int d = G[cur][i].second;
			if (dist[next] == d + total) {
				dirG[next].push_back(cur);
			}
			if (dist[next] > d + total) {
				dirG[next].clear();
				dirG[next].push_back(cur);
				dist[next] = d + total;
				PQ.push(make_pair(dist[next], next));
			}
		}
	}
	//printf("\n");
	for (int i = 1; i <= n; i++) {
		int a = dist[i];
		ans1 += a;

		int minval = 987654321;
		queue<int> Q;
		Q.push(i);
		while (!Q.empty()) {
			int cur;
			cur = Q.front();
			Q.pop();
			if (dist[cur] == 0) {
				minval = MIN(cur, minval);
				continue;
			}
			for (int j = 0; j < dirG[cur].size(); j++) {
				int next = dirG[cur][j];
				Q.push(next);
			}
		}

		//printf("%d %d\n", i, cur);
		ans2 += minval;
	}

	return;
}



int main(int argc, char** argv) {
	//setbuf(stdout, NULL);

	int TC;
	scanf("%d", &TC);	// cin 사용 가능
	for (int test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		scanf("%d %d %d", &n, &m, &K);
		init();
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			G[a].push_back(make_pair(b, c));
			G[b].push_back(make_pair(a, c));
		}
		for (int i = 0; i < K; i++) {
			int a;
			scanf("%d", &a);
			start.push_back(a);
		}
		// 이 부분에서 정답을 출력하십시오.
		f();
		
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%lld\n", ans1);
		printf("%lld\n", ans2);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}