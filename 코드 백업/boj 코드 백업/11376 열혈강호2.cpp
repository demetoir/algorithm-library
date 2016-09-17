#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define MAX(a,b) (((a)>(b))? (a):(b))
#define MIN(a,b) (((a)<(b))? (a):(b))
#define ABS(a) (((a)<(0))? (-(a)):(a))
#define ll long long
#define si(a) scanf("%d",&a)

int n, m,k;
#define MAX_N 1001
#define MAX_M 1001

vector<int> A[MAX_N];
int B[MAX_M];
bool check[MAX_N];

bool dfs(int cur) {
	if (check[cur] == true) {
		return false;
	}
	check[cur] = true;
	for (int i = 0; i < A[cur].size(); i++) {
		int next = A[cur][i];
		if (B[next] == -1 || dfs(B[next])) {
			B[next] = cur;
			return true;
		}
	}
	return false;
}
int matching() {
	int maxflow = 0;
	for (int i = 0; i <= m; i++) {
		B[i] = -1;
	}
	for (int i = 1; i <= n; i++) {
		memset(check, false, sizeof(check));
		maxflow += dfs(i);
	}
	for(int i =1,count = 0; i<=n&& k>0;i++){
		memset(check, false, sizeof(check));
		int val = dfs(i);
		maxflow += val;
		k -= val;
	}

	return maxflow;
}
int main() {
	si(n); si(m); si(k);
	for (int i = 1, a; i <= n; i++) {
		si(a);
		for (int j = 0; j < a; j++) {
			int b;
			si(b);
			A[i].push_back(b);
		}
	}
	int ans = matching();
	printf("%d\n", ans);
	return 0;
}
