// LCA(least common ancestor) 최소 공통 조상
// 
//시간복잡도 O(n) or O(log n)
//
//
//
//참고자료
//
//http://virtual1409.blogspot.kr/2015/12/lcalca-least-common-ancestor.html
//https://hgkim.gitbooks.io/algorithm/content/lca.html
//
//문제
//
//

// O(n) 버전
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 10000
int l, c;
vector<int>  G[MAXN], check, depth, parent;
void init() {
	for (int i = 0; i < MAXN; i++) G[i].clear();
	check = vector<int>(l + 1);
	parent = vector<int>(l + 1);
	depth = vector<int>(l + 1);
}
void dfs(int cur, int level) {
	check[cur] = 1;
	depth[cur] = level;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		if (check[next]) continue;
		parent[next] = cur;
		dfs(next, level + 1);
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);

	while (!(depth[a] == depth[b])) a = parent[a];

	while (!(a == b)) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}



// O(logn) 버전
#define MAXN			100001
#define BITSIZE			21
vector<int> G[MAXN], check, parent, depth;
int LCA[MAXN][BITSIZE];
int l, c;

void dfs(int cur, int level) {
	check[cur] = true;
	depth[cur] = level;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		if (check[next])continue;
		parent[next] = cur;

		LCA[next][0] = cur;
		for (int b = 1; b < BITSIZE; b++) {
			LCA[next][b] = LCA[LCA[next][b - 1]][b - 1];
		}
		dfs(next, level + 1);
	}
}
int lca(int a, int b) {
	if (depth[a] < depth[b])swap(a, b);

	for (int i = BITSIZE - 1; i >= 0; i--) {
		if ((1 << i) <= depth[a] - depth[b]) {
			a = LCA[a][i];
		}
	}
	if (a == b)return a;

	for (int i = BITSIZE - 1; i >= 0; i--) {
		if (LCA[a][i] != LCA[b][i]) {
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}
	return LCA[a][0];
}















