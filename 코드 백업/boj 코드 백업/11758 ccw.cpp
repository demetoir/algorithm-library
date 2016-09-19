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
int main() {
	for (int i = 0; i < 3; i++) {
		si(x[i]);
		si(y[i]);
	}
	ans = x[0] * y[1] + x[1] * y[2] + x[2] * y[0] - (x[0] * y[2] + x[1] * y[0] + x[2] * y[1]);
	
	if (ans < 0)ans =- 1;
	if (ans > 0) ans = 1;
	printf("%d\n", ans);
	

	return 0; 
}

