#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
#define si(a) scanf("%d",&(a))
#define MAX_N 100000


int n;
vector <int> tree;
int ans;

int getsum(int index) {
	int ret = 0;
	while (index > 0) {
		ret += tree[index];
		index -= (index & -index);
	}
	return ret;
}
void update(int index, int diff) {
	while (index < tree.size()) {
		tree[index] += diff;
		index += (index & -index);
	}
}
int main() {
	si(n);
	tree = vector<int>(MAX_N +1);
	for (int i = 0,a,b; i < n; i++) {
		si(a); si(b);
		int l = getsum(a);
		int r = getsum(b);
		printf("%d\n", l+r);

		update(a, -l); update(a + 1, l);
		update(b, -r); update(b + 1, r);

		update(a + 1, 1);
		update(b, -1);
	}
	
	return 0;
}