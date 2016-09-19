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
#define INF (1<<30)
#define LLINF ((LL)1<<61)
//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 501

int n;
int psum [MAX_N];
int memo[MAX_N][MAX_N];

int find(int x, int y){
	if (x>y)return INF;
	
	if (x == y) return 0;
	if (memo[x][y]!= 0)
		return memo[x][y];
		
	int ret = 0;
	int val = psum[y] - psum[x-1];
	
	ret = min(
		find(x+1,y)+val,
		find(x,y-1)+ val
	);
	int a = INF;
	for(int i =x;i<y;i++){		
		a = min(a,find(x,i) + find(i+1,y));
	}
	
	ret = min(ret,a+val);
	memo[x][y] = ret;
	return ret;
}


int main() {
	int test;
	si(test);
	for(;test>0; test--){
		si(n);
		memset(psum,0,sizeof(psum));
		memset(memo,0,sizeof(memo));
		psum[0] = 0;
		for(int i =0,val; i<n; i++){
			si(val);

			psum[i+1]= psum[i] +val;
		}
				
		int ans = 0;
		
		ans = find(1,n);
		
		printf("%d\n",ans);
	}
	

	return 0;
}











