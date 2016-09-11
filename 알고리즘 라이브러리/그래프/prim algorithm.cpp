//prim algorithm (프림 알고리즘 알고리즘)
//
//시간 복잡도
//
//참고자료
//
//문제
//1197 최소 스패닝 트리 https://www.acmicpc.net/problem/1197
//7627 스패닝 트리 https://www.acmicpc.net/problem/7627
//검증 됨

#include <queue>
#include <vector>

using namespace std;

#define MAX_V 10000
#define MAX_E 100000
#define pii pair<int,int>
struct Edge {
	int cost;
	int cur;
	int next;
	Edge(int _cur, int _next, int _cost) :cur(_cur), next(_next), cost(_cost) {};
};

bool operator <(Edge A, Edge B) {
	return A.cost > B.cost;
}
vector<pii>G[MAX_V];

int prim() {
	int totalcost = 0;
	int start_vertex = 0;
	int edgecount = 0;
	priority_queue<Edge>pq;
	vector<bool> vertex_check(MAX_V);
	vertex_check[start_vertex] = true;

	for (int i = 0; i < G[start_vertex].size(); i++) {
		int next = G[start_vertex][i].first;
		int cost = G[start_vertex][i].second;
		pq.push(Edge(start_vertex, next, cost));
	}
		
	while (!pq.empty()) {
		int cur = pq.top().cur;
		int next = pq.top().next;
		int cost = pq.top().cost;
		pq.pop();

		if (vertex_check[cur] == vertex_check[next] == true)continue;

		totalcost += cost;
		edgecount += 1;
		int next_v;
		if (vertex_check[cur] == false)
			next_v = cur;
		if (vertex_check[next] == false)
			next_v = next;

		for (int i = 0; i < G[next_v].size(); i++) {
			int next = G[next_v][i].first;
			int cost = G[next_v][i].second;
			pq.push(Edge(next_v, next, cost));
		}
		if (edgecount == MAX_V - 1)
			break;
	}
	return totalcost;
}
