#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sLL(a) scanf("%lld",&(a))
#define MP pair<int,int>
#define INF 1234567890
#define LLINF 1234567890123456789
//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1000000


vector <int> tree;
vector <int> lazy;
int n, m;

void update_lazy(int node, int left , int right) {
	if (left != right) {
		int mid = (right - left)/2;
		int val = 0;

		lazy[node * 2] ++;
		lazy[node * 2 + 1]++;
		lazy[node * 2] %= 2;
		lazy[node * 2 + 1] %= 2;

		if (lazy[node * 2] == 0)
			val += tree[node * 2];
		else
			val += mid - left + 1 - tree[node * 2];

		if (lazy[node * 2 + 1] == 0)
			val += tree[node * 2 + 1];
		else
			val += right - (mid +1)+1 - tree[node * 2 + 1];

		tree[node] = val;
	}
	else {
		tree[node]++;
		tree[node] %= 2;
	}

}
int sum(int node,int left , int right , int a,int b) {
	if (lazy[node] != 0) {
		update_lazy(node, left, right);
		lazy[node] = 0;
	}

	if (b < left || right < a)return 0;
	if (a <= left && right <= b) return tree[node];
	int mid = (left+right)/2;
	return sum(node * 2, left, mid, a, b) +
		sum(node * 2 + 1, mid + 1, right, a, b);

}
void update(int node , int left , int right, int a, int b) {
	if (lazy[node] != 0) {
		update_lazy(node, left, right);
		lazy[node] = 0;
	}

	if (b < left || right < a)return;

	//°»½Å
	if (a <= left && right <= b) {
		update_lazy(node, left, right);
		lazy[node] = 0;
		return;
	}

	int mid = (left + right) / 2;
	update(node * 2, left, mid, a, b);
	update(node * 2 + 1, mid+1, right, a, b);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int o, s, t;


int main() {

	si(n); si(m);
	int h = ceil(log2(n));
	int size = 1 << (h + 1);
	tree = vector< int>(size);
	lazy = vector< int>(size);

	for (int i = 0; i<m; i++) {
		si(o); si(s); si(t);
		s--;
		t--;
		if (o == 0) {
			update(1,0, n-1, s, t);
		}
		else {
			int val = sum(1, 0, n-1, s, t);
			printf("%d\n", val);
		}
	}
	return 0;
}











