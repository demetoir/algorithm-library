#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
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

#define FOR(i,s,e) for (int i = s; i<e; i++)
//////////////////////////////////////////////////////////////////////////////////

#define MAX_N 1000001
#define MAX_M 6001

int n, m;
int num[10];
int check[MAX_N];
int ans = INF;

int main() {
	int test;
	si(n);
	si(m);
	for (int i = 0, val; i < m; i++) {
		si(val);
		num[val] = 1;
	}
	ans = abs(100 - n);
	if (num[0] == 0) {
		ans = min(ans,n + 1);
	}
	for (int i = 1; i < MAX_N; i++) {
		bool flag = false;
		int cur = i;
		int len=0;
		while (cur > 0){
			if (num[cur % 10] == 1)flag = true;
			cur = cur / 10;
			len += 1;
		}
		if (flag == false) {
			ans = min(ans, abs(n - i) + len);
		}
	}


	printf("%d\n", ans);
	return 0;
}

