//index tree (fenwick tree)
//시간복잡도
//get O(log n)
//update O(log n)

//문제

//2934 LRH 식물 https://www.acmicpc.net/problem/2934


#include <vector>
#include <math.h>
using namespace std;
#define MAX_N 100001 //10^6

int n;
vector <int>tree(n);
void update(int i, int diff) {
	while (i < n) {
		tree[i] += diff;
		i += (i & -i);
	}
}
int getsum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}




