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
#define MP pair<int,int>
#define INF (1<<31 -1)
#define LLINF (((LL)1)<<63  -1)
//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 501

int n;
int memo[MAX_N][MAX_N];
int left[MAX_N],right[MAX_N];


int find(int x, int y){
	if (x>y)return INF;
	
	if (x == y) return 0;
	if (memo[x][y]!= 0)
		return memo[x][y];
		
	int ret = INF;
	
	for(int i =x;i<y;i++){		
		int val = left[x]*right[i]*right[y];
		ret = min(ret,find(x,i) + find(i+1,y)+ val);
	}
	
	memo[x][y] = ret;
	return ret;
}


int main() {
	si(n);	
	for(int i =0; i<n ;i++) {
		si(left[i]);
		si(right[i]);
	}
			
	int ans = 0;	
	ans = find(0,n-1);
	printf("%d\n",ans);


	return 0;
}











