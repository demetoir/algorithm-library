//segment tree lazy propagation 
// 
//시간 복잡도
//build_tree: O(N lg(N)) 
//update_tree: O(lg(N + k))
//query_tree : O(lg(N + k))
//
//문제 
//10999 구간 합구하기2 https://www.acmicpc.net/problem/10999
//1395 스위치 https://www.acmicpc.net/problem/1395
//7626 직사각형 https://www.acmicpc.net/problem/7626
//5486 mountains https://www.acmicpc.net/problem/5486


#include <vector>
#include <math.h>
using namespace std;

#define MAX_N 1000000
vector <int> tree;
vector <int> lazy;
int n, m;
void update_lazy(int node, int left, int right) {
	tree[node] += (right - left + 1)* lazy[node];
	if (left != right) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
int sum(int node, int left, int right, int a, int b) {
	if (lazy[node] != 0) {
		update_lazy(node, left, right);
		lazy[node] = 0;
	}

	if (b < left || right < a)return 0;
	if (a <= left && right <= b) return tree[node];
	int mid = (left + right) / 2;
	return sum(node * 2, left, mid, a, b) +
		sum(node * 2 + 1, mid + 1, right, a, b);
}

void update(int node, int left, int right, int a, int b) {
	if (b < left || right < a)return;

	if (lazy[node] != 0) {
		update_lazy(node, left, right);
		lazy[node] = 0;
	}

	if (a <= left && right <= b) {
		update_lazy(node, left, right);
		lazy[node] = 0;
		return;
	}

	int mid = (left + right) / 2;
	update(node * 2, left, mid, a, b);
	update(node * 2 + 1, mid + 1, right, a, b);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	n = MAX_N;
	int h = ceil(log2(n));
	int size = 1 << (h + 1);
	tree = vector< int>(size);
	lazy = vector< int>(size);
}
