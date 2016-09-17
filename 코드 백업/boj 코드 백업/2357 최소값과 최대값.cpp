#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define si(a) scanf("%d",&(a));
#define MAXVAL 1234568790
#define MINVAL -1

int n, m;
vector< int> maxtree, mintree;
 
int getMAX(int node, int left, int right, int a, int b) {
	if (b < left || right < a) {
		return MINVAL;
	}
	if (a <= left && right <= b) {
		return maxtree[node];
	}
	int mid = (left + right) / 2;
	return max(getMAX(node * 2, left, mid, a, b), getMAX(node * 2 + 1, mid + 1, right, a, b));
}
int getMIN(int node, int left, int right, int a, int b) {
	if (b < left || right < a) {
		return MAXVAL;
	}
	if (a <= left && right <= b) {
		return mintree[node];
	}
	int mid = (left + right) / 2;
	return min(getMIN(node * 2, left, mid, a, b), getMIN(node * 2 + 1, mid + 1, right, a, b));
}

void updateMAX(int node, int left, int right, int index, int diff) {
	if (index < left || right < index) {
		return;
	}
	maxtree[node] = max(maxtree[node], diff);
	if (left != right) {
		int mid = (left + right) / 2;
		updateMAX(node * 2, left, mid, index, diff);
		updateMAX(node * 2 + 1, mid + 1, right, index, diff);
	}
}

void updateMIN(int node, int left, int right, int index, int diff) {
	if (index < left || right < index) {
		return;
	}
	mintree[node] = min(mintree[node], diff);
	if (left != right) {
		int mid = (left + right) / 2;
		updateMIN(node * 2, left, mid, index, diff);
		updateMIN(node * 2 + 1, mid + 1, right, index, diff);
	}
}


int main() {
	si(n); si(m);
	int h = (int)ceil(log2(n));
	int treesize = 1 << (h + 1);
	maxtree = vector < int >(treesize, MINVAL);
	mintree = vector <int >(treesize, MAXVAL);

	for (int i = 0,val; i < n; i++) {
		si(val);
		updateMIN(1, 0, n - 1, i, val);
		updateMAX(1, 0, n - 1, i, val);
	}

	for (int i = 0,a,b; i < m; i++) {
		si(a); si(b);

		int minval = getMIN(1, 0, n - 1, a - 1, b - 1);
		int maxval = getMAX(1, 0, n - 1, a - 1, b - 1);
		printf("%d %d\n", minval, maxval);
	}

	return 0;
}
