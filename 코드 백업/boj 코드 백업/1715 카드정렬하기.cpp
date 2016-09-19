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
int n, m;
LL ans;
int A[12];
int B[12];
priority_queue<int> pq;
int main() {
	si(n);
	for (int i = 0, val; i < n; i++) {
		si(val);
		pq.push(-val);
	}
	int ans = 0;
	while (pq.size() > 1) {
		int a = -pq.top();
		pq.pop();
		int b = -pq.top();
		pq.pop();
		pq.push(-a - b);
		ans += a + b;
	}
	printf("%d\n", ans);
	

	return 0; 
}

