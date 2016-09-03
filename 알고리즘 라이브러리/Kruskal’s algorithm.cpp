// Kruskal’s algorithm (크루스칼 알고리즘)
//
//시간 복잡도 O(Elog(v))
//
//선행 조건
//union-find 나 set이 필요하다
//
//참고자료
//https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
//
//검증됨
//문제
//1197 최소 스패닝 트리 https://www.acmicpc.net/problem/1197
//7627 스패닝 트리 https://www.acmicpc.net/problem/7627
//
#include <vector>
#include <queue>
#include <set>
using namespace std;

//usion find를 사용한 크루스칼 알고리즘
#define MAX_V 10000
#define MAX_E 100000
struct Edge{
	int cur;
	int next;
	int cost;
};
Edge edge[MAX_E];

int parent[MAX_V];
int level[MAX_V];
int init_union_find() {
	for (int i = 0; i < MAX_V; i++) {
		parent[i] = i;
		level[i] = 0;
	}
}

int find(int cur){
	if (parent[cur] == cur)return cur;
	return parent[cur] = find(parent[cur]);
}

void unite(int A, int B) {
	int a = find(A);
	int b = find(B);
	if (a == b)return;

	if (level[a] < level[b]) {
		parent[a] = b;
	}
	else {
		parent[b] = a;
		if (level[a] == level[b])
			level[a]++;
	}
}

bool cmp(Edge A, Edge B) {
	return A.cost < B.cost;
}

int Kruskal() {
	init_union_find();
	sort(edge, edge + MAX_E, cmp);
	int totalcost = 0;
	int edgecount = 0;
	for (int i = 0; i < MAX_E; i++) {
		int a = edge[i].cur;
		int b = edge[i].next;
		int cost = edge[i].cost;

		if (find(a) == find(b)) continue;
		
		unite(a, b);
		totalcost += cost;
		edgecount++;
		if (edgecount == MAX_V)
			break;
	}
	return totalcost;
}


//set을 이용한 크루스칼 알고리즘
//미완성
set<int> vertex_set;
bool cmp(Edge A, Edge B) {
	return A.cost < B.cost;
}

int Kruskal() {
	sort(edge, edge + MAX_E, cmp);
	int totalcost = 0;
	int edgecount = 0;
	for (int i = 0; i < MAX_E; i++) {
		int a = edge[i].cur;
		int b = edge[i].next;
		int cost = edge[i].cost;

		if (find(a) == find(b)) continue;

		unite(a, b);
		totalcost += cost;
		edgecount++;
		if (edgecount == MAX_V)
			break;
	}
}



