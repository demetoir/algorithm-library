#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>

#define si(a) scanf("%d",&(a))
#define pi(a) printf("%d\n",(a))
#define FOR(i,a,b) for(i=a;i<b;i++)
#define pii pair<int, int>
#define ll long long int

using namespace std;

pii line[100001], dp[100001];
int emi[100001];

bool cmp(pii a, pii b)
{
	return a.first < b.first;
}

bool _cmp(pii a, pii t)
{
	return a.second < t.second;
}

int main()
{
	int N; si(N);
	int a, b, i;

	FOR(i, 0, N) {
		si(a); si(b);
		pii temp(a, b);
		line[i] = temp;
	}

	sort(line, line + N, cmp);

	dp[0] = line[0];
	int size = 0, se = 0;

	FOR(i, 1, N)
	{
		pii t = line[i];
		if (dp[size].second < t.second)
		{
			dp[++size] = t;
			continue;
		}
		int it = lower_bound(dp, dp + size, t, _cmp) - dp;
		emi[se++] = dp[it].first;
		dp[it] = t;
	}

	pi(N - size - 1);

	sort(emi, emi + se);

	FOR(i, 0, se)
		pi(emi[i]);

	return 0;
}