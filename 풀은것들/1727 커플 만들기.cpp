//dp 슬라이딩윈도우, 정렬 ,아이디어, 막대기 나누기
//
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

#define LL long long
#define MP pair < int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define INF 1234567890
#define LLINF 12345678912345678
//////////////////////////////////////////////////////////////////////////////////////////
#define MAX_N 1001

LL dp1[MAX_N];
LL dp2[MAX_N];
int n, m;
int A[MAX_N];
int B[MAX_N];
int match = 0;
//index = 1부터 시작


int main() {
	si(n);
	si(m);
	for (int i = 0; i < n; i++)
		si(A[i]);
	for (int i = 0; i < m; i++)
		si(B[i]);
	sort(A, A + n);
	sort(B, B + m);
	match = min(n, m);
	if (n > m) {
		swap(A, B);
		swap(n, m);
	}

	fill(dp1, dp1 + MAX_N, LLINF);
	fill(dp2, dp1 + MAX_N, LLINF);

	dp1[0] = 0;
	for (int i = 1; i <= n; i++) {
		LL minval = dp1[i - 1];
		memset(dp2, 0, sizeof(dp2));

		//i번쟤가 j번째를 선택할떄 최적
		for (int j = i; j <= m; j++) {
			dp2[j] = minval + abs(A[i - 1] - B[j - 1]);
			minval = min(minval, dp1[j]);
		}
		swap(dp1, dp2);
	}

	LL ans = LLINF;
	for (int i = match; i <= m; i++) {
		ans = min(ans, dp1[i]);
	}

	printf("%lld\n", ans);

	return 0;
}


