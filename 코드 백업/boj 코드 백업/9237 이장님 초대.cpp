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

int n;
int ans;

int l[MAX_N];
int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		si(l[i]);
	}
	sort(l, l + n);
	for (int i = 0; i < n; i++) {
		ans = max(ans, l[i] + n-i);
	}
	printf("%d\n", ans+1);


	return 0; 
}

