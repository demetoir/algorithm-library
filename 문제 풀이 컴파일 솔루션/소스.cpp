#include <iostream>
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
#define sc(a) scanf("%c",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define pii pair<int,int>
#define INF 2e9
#define LLINF ( (((LL)1) <<63)  -1)
#define AND &&
#define OR ||
#define FOR(i,s,e) for (int i = s; i<e; i++)
//////////////////////////////////////////////////////////////////////////////////

int n, m;
struct Maxflow {
	int size;
	struct Edge {
		int next;
		int flow;
		int rev_index;
		Edge(int n, int f, int r) {
			next = n;
			flow = f;
			rev_index = r;
		}
	};
	vector< vector<Edge> > G;

	Maxflow(int n) {
		size = n;
		G.assign(size, vector<Edge>());
	}

	void make_edge(int cur, int next, int flow, int rev_flow) {
		Edge A(next, flow, G[next].size());
		Edge B(cur, rev_flow, G[cur].size());
		G[cur].push_back(A);
		G[next].push_back(B);
	}

	int bfs(int s, int t) {
		int flow = INF;
		vector <pii> parent(size, pii(-1, -1));
		vector <bool> check(size, false);
		queue<int>q;
		q.push(s);
		check[s] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int i = 0; i < G[cur].size(); i++) {
				Edge &e = G[cur][i];

				if (e.flow > 0 && check[e.next] == false) {
					check[e.next] = true;
					q.push(e.next);
					parent[e.next].first = cur;
					parent[e.next].second = i;
				}
			}
		}

		if (parent[t].first == -1) return 0;

		for (int p = t; parent[p].first != -1; p = parent[p].first) {
			Edge &e = G[parent[p].first][parent[p].second];
			flow = min(flow, e.flow);
		}

		for (int p = t; parent[p].first != -1; p = parent[p].first) {
			Edge &e = G[parent[p].first][parent[p].second];
			e.flow -= flow;
			G[e.next][e.rev_index].flow += flow;
		}
		return flow;
	}

	int getmaxflow(int s, int t) {
		int maxflow = 0;
		int flow = 0;
		while (flow = bfs(s, t))
			maxflow += flow;
		return maxflow;
	}

};

char str[100];
#define MAX_N 51
int board[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
int r[MAX_N][MAX_N];
int s, t;
Maxflow mf(5010);
void makeG() {
	int count = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || r[i][j] != 0) continue;

			for (int k = 0; k < 51; k++) {
				if (j + k >= m)break;
				if (board[i][j + k] == 0) break;
				r[i][j + k] = count;
			}
			mf.make_edge(s, count, 1, 0);
			count += 1;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0 || d[i][j] != 0) continue;

			for (int k = 0; k < 51; k++) {
				if (i + k >= n)break;
				if (board[i + k][j] == 0) break;
				d[i + k][j] = count;
			}
			mf.make_edge(count, t, 1, 0);
			count += 1;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) continue;
			mf.make_edge(r[i][j], d[i][j], 1, 0);
		}
	}
}
int main() {
	cin >> n >> m;
	int val;
	s = 0;
	t = 5001;
	for (int i = 0; i < n; i++) {
		ss(str);
		for (int j = 0; j < m; j++) {
			if (str[j] == '*')
				board[i][j] = 1;
			else board[i][j] = 0;
		}
	}
	makeG();

	int ans = mf.getmaxflow(s, t);
	printf("%d\n", ans);
	return 0;
}