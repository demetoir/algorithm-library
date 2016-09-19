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

#define MAX_N 100001
#define MAX_M 6001

int n, m;
LL l[MAX_N];
int ansa, ansb;
LL ansval = LLINF;
int main() {

	si(n);
	for (int i = 0; i < n; i++)
		sLL(l[i]);

	for (int i = 0; i < n; i++) {
		int index = lower_bound(l, l + n, -l[i]) - l;

		if (i != index AND index < n AND ansval > abs(l[i] + l[index])) {
			ansa = l[i];
			ansb = l[index];
			ansval = abs(l[i] + l[index]);
		}

		index++;
		if (i != index AND index < n AND ansval > abs(l[i] + l[index])) {
			ansa = l[i];
			ansb = l[index];
			ansval = abs(l[i] + l[index]);
		}

		index -= 2;
		if (i != index AND 0 <= index AND ansval > abs(l[i] + l[index])) {
			ansa = l[i];
			ansb = l[index];
			ansval = abs(l[i] + l[index]);
		}
	}
	printf("%d %d\n", ansa, ansb);


	return 0;
}

