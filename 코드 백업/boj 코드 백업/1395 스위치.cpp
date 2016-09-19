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
#define INF 1234567890
#define LLINF 1234567890123456789
//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1000000


int tree[MAX_N+1];
 
int n,m;

int a[MAX_N];

int sum(int i){
	int ret = 0;
	
	while (i>0){
		ret +=tree[i];
		i -= (i&-i);		
	}
	return ret;
}
void update(int i, int diff){
	while (i<=MAX_N){
		tree[i] += diff;
		i += (i & -i);		
	}
}

int o,s,t;
int main(){
	si(n); si(m);
	
	for (int i =0; i<m; i++){
		si(o);si(s);si(t);
		int val = sum(t) - sum(s-1);
		if (o == 0){			
			int after = (t - s +1) - val;
			int diff = -val +after;
			update(s,diff);
			update(t+1,-diff);			
		}
		else{
			printf("%d\n",val);
		}
		
	}
	
	
	
	
	
	
	
	return 0;
}

















