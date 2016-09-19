#include<stdio.h>
#include<string.h>
#define SIZE  1000010
int n, m;
int root[SIZE];
int rain[SIZE];
int ans = 1;
int ansL[SIZE];
int last[SIZE];

int find(int x) {
	if (x >= m)return m;
	if (root[x] == x)return x;
	return root[x] = find(root[x]);
}

void Union(int x, int y) {
	int p = find(x);
	int q = find(y);
	root[p] = q;
}

int main() {
	int test;
	scanf("%d", &test);
	for (; test > 0; test--) {

		memset(ansL, 0, sizeof(int)*SIZE);
		memset(rain, 0, sizeof(int)*SIZE);
		memset(last, 0, sizeof(int)*SIZE);
		scanf("%d%d", &n, &m);

		for (int i = 0; i < m; i++)scanf("%d", &rain[i]);

		root[m] = m;
		ans = 1;
		for (int i = m - 1; i>-1; i--) {
			if (rain[i] > 0)root[i] = root[i + 1];
			else root[i] = i;
		}
		for (int i = 0; i<m; i++) {
			if (rain[i] == 0)continue;
			int x = find(last[rain[i]]);
			if (x >= i || x >= m) {
				ans = 0;
				break;
			}
			ansL[x] = rain[i];
			Union(x, x + 1);
			last[rain[i]] = i;
		}

		if (ans == 0)printf("NO\n");
		else {
			printf("YES\n");
			for (int i = 0; i < m; i++)
				if (rain[i] == 0)printf("%d ", ansL[i]);

			printf("\n");
		}
	}
}
