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
#define MAX_N 2010
int n,k;
int ans;
int A[6], B[6];
int out = -INF;
int in;
int main() {
	si(k);
	for (int i = 0; i < 6; i++) {
		si(A[i]); si(B[i]);
	}

	for (int i = 0; i < 6; i++) {
		int val = B[i] * B[(i + 1) % 6];
		if (val > out) {
			out = val;
			ans = (val - (B[(i + 3) % 6] * B[(i + 4) % 6]))*k;
		}
	}

	printf("%d\n", ans);
	return 0;
}




