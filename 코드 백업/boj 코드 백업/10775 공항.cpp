#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sf(a) scanf("%f",&(a))
#define LL long long
#define MOD 1000000000
#define PRIME_SIZE 8
#define MAX_N 100000

int G, p;
int ans;
int g[MAX_N + 1];
int tree[MAX_N + 1];
int rank[MAX_N + 1];
int aroot, broot;
int root;


int find(int cur) {
	if (tree[cur] == cur) return cur;

	tree[cur] = find(tree[cur]);
	return tree[cur];
}

void uion(int a, int b) {
	if (a < b)
		tree[b] = a;
	else
		tree[a] = b;
}



int main() {
	for (int i = 0; i < MAX_N + 1; i++)
		tree[i] = i;

	si(G);
	si(p);
	for (int i = 0; i < p; i++) 
		si(g[i]);

	for (int i = 0; i < p; i++) {
		g[i];
		aroot = find(g[i]);
		if (aroot == 0)
			break;
		
		broot = find(aroot - 1);
		uion(aroot, broot);
		ans += 1;
	}


	


	printf("%d\n", ans);

	return 0;
}