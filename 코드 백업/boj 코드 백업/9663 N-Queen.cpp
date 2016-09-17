#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 100
#define si(a) scanf("%d",&(a))
#define MP pair<int,int>
#define LL long long
#define INF 1234567890

int n;
int ans;
int queen[20];
void find(int k) {
	if (k == n) {
		ans += 1;
		return;
	}
	for (int i = 0; i < n; i++) {	
		if (queen[i] != INF) continue;
		int flag = true;
		for (int j = 0; j < n; j++) {
			if (i + j < n && queen[i + j] == k - j )
				flag = false;
			if (i - j >= 0 && queen[i - j] == k - j) 
				flag = false;
		}
		if (flag) {
			queen[i] = k;
			find(k + 1);
			queen[i] = INF;
		}
	}
}

int main() {
	si(n);
	for (int i = 0; i < n; i++)
		queen[i] = INF;
	find(0);
	printf("%d\n", ans);
	return 0;
}