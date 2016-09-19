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
#define LLINF (((LL)1)<<63  -1)
//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 100
#define BIT_MAX (1<<20)
int n;

char scroll[MAX_N];
char angel[MAX_N],demon[MAX_N];
/// 돌다리, 문자 , 위아래  
int memo[MAX_N][MAX_N][2];

int adj[MAX_N][MAX_N];

int ans;
int main() {
	ss(scroll);
	ss(angel);
	ss(demon);
	int n = strlen(angel);
	int size = strlen(scroll);
	
	memo[0][0][0]= memo[0][0][1] = 1;
	for(int i =1; i<=n; i++ ){		
		for(int j =1; j<=size; j++){
			if(scroll[j-1] == angel[i-1]){
				for(int k=0; k<i; k++)
					memo[i][j][0] += memo[k][j-1][1] ;
			}
			if(scroll[j-1] == demon[i-1]){
				for(int k = 0; k<i; k++)
					memo[i][j][1] += memo[k][j-1][0];				
			}
		} 
		
		
	}
	ans = memo[n][size][0]+memo[n][size][1];

	printf("%d\n", ans);

	return 0;
}











