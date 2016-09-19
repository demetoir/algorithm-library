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
#define ss(a) scanf("%s",a)
#define MP pair<int,int>
#define INF (1<<31 -1)
#define LLINF ( (((LL)1) <<62)  -1)
#define AND &&
#define OR ||

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 200001

LL maxans = 0;
LL minans = LLINF;
int block[MAX_N];
int ans;

int n,h;
#define TREESIZE 500001
int tree[TREESIZE];
int sum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}
void update(int i, int diff) {
	while (i <= TREESIZE) {
		tree[i] += diff;
		i += (i & -i);
	}
}
int main() {
	si(n);si(h);

	for (int i = 0,val; i < n; i++) {
		si(val);
		if (i % 2 == 0) {
			update(1, 1);
			update(val+1, -1);
		}
		else {
			update(h-val+1, 1);
		}
	}

	int ansnum = 0;
	int ansval = INF;

	for (int i = 1; i <= h; i++) {
		int val = sum(i);
		//printf("%d %d\n", i, val);
		if (val == ansval) {
			ansnum += 1;
		}
		else if (val < ansval) {
			ansval = val;
			ansnum = 1;
		}	
	}

	printf("%d %d\n", ansval,ansnum);

	return 0;
}