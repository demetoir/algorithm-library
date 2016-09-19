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
#define AND &&
#define OR ||

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 25
int memo[MAX_N][MAX_N][MAX_N];
int f(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)return 1;

	if (a > 20 || b > 20 || c > 20)return f(20, 20, 20);

	if (memo[a][b][c] > 0)return memo[a][b][c];

	int ret = 0;
	if (a < b && b < c) ret = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c);
	else ret = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
	
	memo[a][b][c] = ret;
	
	return ret;

}
int a, b, c;
int main() {
	while (1) {
		si(a); si(b); si(c);
		if (a == -1 && b == -1 && c == -1)break;
		printf("w(%d, %d, %d) = %d\n",a,b,c, f(a, b, c));
	}

	return 0;
}




