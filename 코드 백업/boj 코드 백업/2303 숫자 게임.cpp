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

#define FOR(i,s,e) for (int i = s; i<e; i++)


//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1001
int x[3];
int y[3];
int ans;
int n;
int l[5];
int ansval = 0;
int main() {
	si(n);

	for (int iter = 0; iter < n; iter++) {
		for (int i = 0; i < 5; i++) 
			si(l[i]);
		int val = 0;
		FOR(i, 0, 5) {
			FOR(j, i+1, 5) {
				FOR(k, j + 1, 5) {
					val = max(val, (l[i] + l[j] + l[k]) % 10);
				}
			}
		}
		if (ansval <= val) {
			ans = iter + 1;
			ansval = val;
		}
	}
	printf("%d\n", ans);

	return 0; 
}

