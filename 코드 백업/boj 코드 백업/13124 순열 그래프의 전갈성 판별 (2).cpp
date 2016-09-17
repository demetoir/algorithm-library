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

int n,q;
int a[MAX_N+1];

int main(){
	si(n);
	for(int i =1; i<=n;i++){
		si(a[i]);
	}
	si(q);
	for(int x,y;q>0;q--){
		si(x);si(y);
		
		int t = a[x];
		a[x] = a[y];
		a[y] = t;
		
		if((a[1] == 3 && a[2]==1 && a[n]==2)
			||(a[0]== n-1 && a[n-1] == n && a[n] == n-2)
			||(a[1] == 2 && a[2] == n && a[3] == 1)
			||(a[n-2] == n && a[n-1] ==1 & a[n] == n-1)){
				printf("YES\n");
			}
		else{
			printf("NO\n");
		}	
		
	}	
	
	
	return 0;
}
