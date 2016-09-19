#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define si(a) scanf("%d",&a)
#define MAX_N 51
#define MAX(a,b) ( ((a)>(b)) ? (a):(b) )
#define sc(a) scanf("%c",&(a));
int n;
int G[MAX_N][MAX_N];

int ans = 0;
int grade[MAX_N];
vector<int> check;
vector<int>back;

int target;
bool dfs(int cur) {
	if (check[cur] == true) {
		return false;
	}
	check[cur] = true;

	for (int i = 0; i < n; i++) {
		int next = i;
		if (grade[next] == target)continue;
		if (G[cur][next] == false) continue;

		if (back[next] == -1 || dfs(back[next]) == true) {
			back[next] = cur;
			return true;
		}
	}
	return false;
}

int match(){
	int maxflow = 0;
	back = vector<int>(MAX_N, -1);

	for (int i = 0; i < n; i++) {
		int next = i;
		if (grade[next] == target)continue;
		check = vector<int>(MAX_N,false);
		if (dfs(i) == true) {
			maxflow++;
		}
	}

	return maxflow;
}

int solve() {
	int ret = 0;
	int maxmatch = match();
	int val = 0;
	for (int i = 0; i < n; i++) {
		if (grade[i] == target) {
			val += 1;
		}
	}
	ret = n- maxmatch / 2;
	return  ret;
}
int main() {
	si(n);
	scanf("\n");
	for (int i = 0; i < n; i++) {
		sc(grade[i]);
		grade[i] -= '0';
	}
	scanf("\n");

	for (int i = 0; i < n; i++) {
		char s[123];
		scanf("%s", s);
		for (int j = 0; j < n; j++) {
			if (s[j] == 'Y') {
				G[i][j] = 1;
			}
			else {
				G[i][j] = 0;
			}
		}

	}
	ans = 0;
	int val = 0;

	target = 1;
	val = solve();
	ans = MAX(ans, val);

	target = 2;
	val = solve();
	ans = MAX(ans, val);
	
	target = 3;
	val = solve();
	ans = MAX(ans, val);


	printf("%d\n", ans);


	return 0;
}