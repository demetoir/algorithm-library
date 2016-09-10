// maxflow (최대유량)
//
//알고리즘을 이해 하고 쓰는것도 중요하지만 그래프를 모델링하는 방법을 익혀야한다
//
//Ford-Fulkerson, edmond karp 두가지 방식이있다
//Ford_Fulkerson 은 경로를 dfs 로 찾고
//edmond karp 는 경로를 bfs 로 찾는다
//일반적으로 dfs를 쓰는것보다는 bfs 를 쓰는방식이 더 빠르다
//더 빠른 방법으로는 Dinic algorithm, Hopcroft-karp 가 있지만 생략한다
//
//시간 복잡도 O(V*E^2)
//
//참고자료
//https://en.wikipedia.org/wiki/Maximum_flow_problem
//https://1ambda.github.io/91/algorithm/algorithm-part2-5/
//http://m.blog.naver.com/choyi0521/80207731515
//http://musicdiary.egloos.com/4207458
//http://musicdiary.egloos.com/4213579
//
//문제
//11375 열혈강호 https://www.acmicpc.net/problem/11375
//2188 축사 배정 https://www.acmicpc.net/problem/2188
//1298 노트북의 주인을 찾아서 https://www.acmicpc.net/problem/1298
//1017 소수 쌍 https://www.acmicpc.net/problem/1017
//11376 열혈강호 2 https://www.acmicpc.net/problem/11376
//1671 상어의 저녘식사 https://www.acmicpc.net/problem/1671
//11377 열혈강호 3 https://www.acmicpc.net/problem/11377
//11378 열혈강호 4 https://www.acmicpc.net/problem/11378
//1799 비숍 https://www.acmicpc.net/problem/1799
//2316 도시 왕복하기 https://www.acmicpc.net/problem/2316


#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

//인접 행렬 버전
#define MAX_V 1000
#define INF 2e9
#define pii pair<int,int>
int G[MAX_V][MAX_V];
int flow[MAX_V][MAX_V];

int maxflow(int s,int t) {
	int maxflow = 0;
	
	while (1) {
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty() && parent[t] != -1) {
			int cur = q.front(); q.pop();

			for (int next = 0; next < MAX_V; next++) {
				if (G[cur][next] == false) continue;
				if (parent[next] == -1 && flow[cur][next] > 0) {
					parent[next] = cur;
					q.push(next);
				}
			}
		}
		if (parent[t] == -1) break;

		int amount = INF;
		for (int p = s; parent[p] != -1; p = parent[p]) {
			amount = min(amount, flow[parent[p]][p]);
		}

		for (int p = s; parent[p] != -1; p = parent[p]) {
			G[parent[p]][p] -= amount;
			G[p][parent[p]] += amount;
		}
		maxflow += amount;
	}
	return maxflow;
}

//인접 리스트 버전
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

		int flow = INF;
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

