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

char str1[MAX_N];
char str2[MAX_N];
int ans[MAX_N];
int main() {
	ss(str1);
	ss(str2);
	int n = strlen(str1);
	int m = strlen(str2);

	for (int i = n - 1,j = MAX_N-1; i >= 0; i--, j--)
		ans[j] += str1[i] - '0';
	for (int i = m - 1, j = MAX_N - 1; i >= 0; i--, j--)
		ans[j] += str2[i] - '0';

	int i;
	for (i = 0; i < MAX_N; i++)
		if (ans[i] != 0) break;

	for (; i < MAX_N; i++)
		printf("%d", ans[i]);
	printf("\n");
	return 0;
}




