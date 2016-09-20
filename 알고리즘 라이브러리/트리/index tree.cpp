//index tree (fenwick tree)
//시간복잡도
//get O(log n)
//update O(log n)
//
//
//참고 자료
//https://en.wikipedia.org/wiki/Fenwick_tree
//http://blog.secmem.org/486
//https://www.acmicpc.net/blog/view/21
//
//문제
//2042 구간 합구하기 https://www.acmicpc.net/problem/2042
//2934 LRH 식물 https://www.acmicpc.net/problem/2934
//

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


//2차원 index tree 

