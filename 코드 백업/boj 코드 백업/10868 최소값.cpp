#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;
//#define MAX(a,b) ( (a) > (b) ? (a):(b) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )

#define si(a) scanf("%d",&a)

int n, m;
#define INF 1000000001
//int segment[400000];
//int v[400000];
int ans;

//int get( int node, int left, int right, int a, int b) {
//	if (b < left || right < a) {
//		return INF;
//	}
//	if (a <= left && right <= b) {
//		return segment[node];
//	}
//	int mid = (left + right) / 2;	
//	return MIN(get(node * 2, left, mid, a, b) ,
//				get(node * 2 + 1, mid + 1, right, a, b));
//}
int get(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return INF;
	if (left <= start && end <= right)
		return tree[node];
	int a = get(tree, node * 2, start, (start + end) / 2, left, right);
	int b = get(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	return MIN(a,b);
}
//int init(int node, int left, int right) {
//	if (left == right) {
//		return segment[node] = MIN(segment[node], v[left]);
//	}
//	else {
//		int mid = (left + right) / 2;
//		return segment[node] = MIN(init(node * 2, left, mid),
//			init(node * 2 + 1, mid + 1, right));
//	}
//}

int init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else {
		int a = init(arr, tree, node * 2, start, (start + end) / 2);
		int b = init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
		return tree[node] = MIN(a,b);
	}
}

int main() {
	scanf("%d %d", &n, &m);

	int h = (int)ceil(log2(n));
	int treesize = 1 << (h + 1);
	vector < int> segment(treesize);
	vector < int> v(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	init(v, segment, 1, 0, n - 1);

	for (int i = 0, a, b; i < m; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", get(segment, 1, 0, n - 1, a - 1, b - 1));
	}

	return 0;
}