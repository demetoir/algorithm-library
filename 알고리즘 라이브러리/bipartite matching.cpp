//이분 매칭 
// 시간복잡도 O(VE)
//boj 11375 열혈강호
//https://www.acmicpc.net/problem/11375


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