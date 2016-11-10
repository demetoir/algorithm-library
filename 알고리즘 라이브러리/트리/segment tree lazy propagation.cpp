//segment tree lazy propagation 
// 
//시간 복잡도
//build_tree: O(N lg(N)) 
//update_tree: O(lg(N + k))
//query_tree : O(lg(N + k))
//
//참고자료
//
//https://www.acmicpc.net/blog/view/26
//http://bowbowbow.tistory.com/4
//
//문제 
//10999 구간 합구하기2 https://www.acmicpc.net/problem/10999
//1395 스위치 https://www.acmicpc.net/problem/1395
//7626 직사각형 https://www.acmicpc.net/problem/7626
//5486 mountains https://www.acmicpc.net/problem/5486

//10999 구간 합구하기2 의 코드
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define LL long long

int n, m, k;
vector <LL> tree;
LL ans;
vector < int > A;
vector <LL> lazy;

LL getsum(int node, int left, int right, int a, int b) {
	if (lazy[node] != 0) {
		tree[node] += (right - left + 1)*lazy[node];
		if (left != right) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (b < left || right < a)
		return 0;

	if (a <= left && right <= b)
		return tree[node];

	LL sum = 0;
	int mid = (left + right) / 2;
	sum = getsum(node * 2, left, mid, a, b) + getsum(node * 2 + 1, mid + 1, right, a, b);
	return sum;
}

void update(int node, int left, int right, int a, int b, LL diff) {
	if (lazy[node] != 0) {
		tree[node] += (right - left + 1)* lazy[node];
		if (left != right) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (b < left || right < a)
		return;
	if (a <= left && right <= b) {
		tree[node] += (right - left + 1)*diff;
		if (left != right) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}

	int mid = (left + right) / 2;
	update(node * 2, left, mid, a, b, diff);
	update(node * 2 + 1, mid + 1, right, a, b, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

LL init(int node, int left, int right) {
	if (left == right)
		return  tree[node] = A[left];
	int mid = (left + right) / 2;
	tree[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);
	return tree[node];
}

int main() {
	si(n); si(m); si(k);
	int h = ceil(log2(n));
	int treesize = 1 << (h + 1);
	tree = vector<LL>(treesize);
	lazy = vector <LL>(treesize);

	for (int i = 0, val; i < n; i++) {
		si(val);
		A.push_back(val);
	}
	init(1, 0, n - 1);

	for (int i = 0, a, b, c; i < m + k; i++) {
		si(a);
		if (a == 1) {
			long long d;
			si(b); si(c); sLL(d);
			update(1, 0, n - 1, b - 1, c - 1, d);
		}
		else {
			si(b); si(c);
			ans = getsum(1, 0, n - 1, b - 1, c - 1);
			printf("%lld\n", ans);
		}
	}

	return 0;
}