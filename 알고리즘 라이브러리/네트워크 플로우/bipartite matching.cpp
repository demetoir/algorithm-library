//이분 매칭 
// 시간복잡도 O(VE)
//
//참고 자료
//https://en.wikipedia.org/wiki/Matching_(graph_theory)
//http://blog.sisobus.com/2013/10/bipartite-matching.html#.V8pVvZiLQXY
//http://blog.secmem.org/573
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
//3295 단방향 링크 네트워크 https://www.acmicpc.net/problem/3295
//1799 비숍 https://www.acmicpc.net/problem/1799

#include <vector>
#include <string.h>
using namespace std;

#define MAX_N 100001 // 10^6

int n = MAX_N;
vector <int>G[MAX_N];
bool check[MAX_N];
int back[MAX_N];

bool dfs(int cur) {
	if (check[cur] == true)return false;
	check[cur] = true;
	for (int i = 0; i < G[cur].size(); i++) {
		int next = G[cur][i];
		if (back[next] == 0 || dfs(back[next])) {
			back[next] = cur;
			return true;
		}
	}
	return false;
}

int match() {
	int maxmatch = 0;
	memset(back, 0, sizeof(back));

	for (int i = 0; i < n; i++) {
		memset(check, 0, sizeof(check));
		if (dfs(i) == true)
			maxmatch++;
	}
	return maxmatch;
}