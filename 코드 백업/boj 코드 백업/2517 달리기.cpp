#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
#define si(a) scanf("%d",&(a))

int ans;
int n;
vector < pair<int, int> > v, newV;
vector < int > segment;
//left ,right -> 트리범위
//a,b -> 요청한 범위

int update(int node, int left, int right,int index, int diff) {
	if (index < left || right < index) {
		return 0;
	}
	segment[node] += diff;
	int mid = (left + right) / 2;
	if (left != right) {
		update(node * 2, left, mid, index, diff);
		update(node * 2 + 1, mid + 1, right, index, diff);
	}
}

int get(int node, int left, int right, int a, int b) {
	if ( right<  a || b < left) {
		return 0;
	}
	else if (a<= left && right <= b) {
		return segment[node];
	}
	int mid = (left + right) / 2;
	return get(node * 2, left, mid, a, b) 
		+ get(node * 2 + 1, mid + 1, right, a, b);

}
 
int init(int node, int left, int right) {
	if (left == right) {
		return segment[node] = 0;
	}
	else {
		int mid = (left + right) / 2;
		return segment[node] = init(node * 2, left, mid) +
			init(node * 2 + 1, mid + 1, right);
	}
}


int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		int val;
		si(val);
		v.push_back(make_pair(val, i));
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		int a = v[i].first, b = v[i].second;
		newV.push_back(make_pair(b,i));
	}
	sort(newV.begin(), newV.end());

	int h = (int)ceil(log2(n));
	int treesize = 1 << (h + 1);
	segment = vector<int>(treesize);
	init(1, 0, n - 1);

	for (int i = 0; i < n; i++) {
		int val = newV[i].second;
		int index = newV[i].first;
		
		ans = get(1, 0, n - 1, 0, val);
		printf("%d\n", i+1 - ans);
		update(1, 0, n - 1, val, 1);

	}


	return 0;
}