#include <cstdio>
#include <cstring>
#include <vector>

#define ll long long
#define si(a) scanf("%d", &(a));
#define sll(a) scanf("%lld", &(a));
#define pi(a) printf("%d\n", (a));
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define FOR(a,b,c) for((a)=(b);(a)<=(c);(a)++)
#define _FOR(a,b,c) for((a)=(b);(a)<(c);(a)++)

using namespace std;

int n, m, k;
bool vi[1234];
int back[1234];
vector<int> G[1234];

bool dfs(int x) {
	if (vi[x]) return false;
	vi[x] = true;

	int i;
	_FOR(i, 0, G[x].size()) {
		int next = G[x][i];
		if (back[next] == -1 || dfs(back[next])){
			back[next] = x;
			return true;
		}
	}

	return false;
}

int bimatch() {
	int size = 0;
	memset(back, -1, sizeof(back));
	int i, cnt = 0;

	FOR(i, 1, n) {
		memset(vi, false, sizeof(vi));
		if (dfs(i)) size++;
	}

	while (cnt < k) {
		int tmp = cnt;
		FOR(i, 1, n) {
			memset(vi, false, sizeof(vi));
			if (dfs(i)) {
				size++;
				cnt++;
			}
		}
		if (tmp == cnt) break;
	}

	return size;
}

int main() {
	si(n); si(m); si(k);

	int i, j;
	FOR(i, 1, n) {
		int t; si(t);
		_FOR(j, 0, t) {
			int w; si(w);
			G[i].push_back(w);
		}
	}

	pi(bimatch());

	return 0;
}