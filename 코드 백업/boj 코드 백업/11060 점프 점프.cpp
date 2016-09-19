#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define si(a) scanf("%d",&(a))
#define MAX_N 1001
#define INF 1234567890

int n;
int memo[MAX_N];
vector<int> jump;

int main() {
	si(n);
	for (int i = 0,val; i < n; i++) {
		memo[i] = INF;
		si(val);
		jump.push_back(val);
	}

	memo[0] = 0;

	for (int i = 0; i < n; i++) {		
		if (memo[i] == INF) continue;
		for (int k = 1; k <= jump[i]; k++) {
			if (k + i >= n)continue;
			memo[k + i] = min(memo[k + i], memo[i] + 1);
		}
	}
	int ans = memo[n - 1];
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}


