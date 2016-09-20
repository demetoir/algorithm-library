//전처리 dp 그레이코드 아이디어
//아이디어를 찾는게 힘들다
//아이디어는 그리디한 성질인것같고 접근 방식은 거꾸로 접근하기에서 시작한다
//가장 왼쪽 끝에 비트를 만들려면 해야 하는 양과 그거 만들고 남은 
//오른쪽에 있는것들을 다시 비교하면서 비트를 만들거나 지우거나 해야한다
//사실 그레이 코드라 그레이 코드 변환법을 알면 쉽게 풀린다

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sc(a) scanf("%c",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define pii pair<int,int>
#define INF 2e9
#define LLINF ( (((LL)1) <<63)  -1)
#define AND &&
#define OR ||
#define FOR(i,s,e) for (int i = s; i<e; i++)
#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////

#define MAX_N 1000
char num[MAX_N];
int dp[40];
int cur[40];
int main() {
	int test = 1;
	for (int i = 0; i < 40; i++) {
		dp[i] = (1 << i) - 1;
	}
	dp[0] = 1;
	si(test);
	for (; test > 0; test--) {
		ss(num);
		int size = strlen(num);
		int ans = 0;
		memset(cur, 0, sizeof(cur));
		for (int i = 0; i < size - 1; i++) {
			if (cur[i] == num[i] - '0')continue;

			ans += dp[size - i - 1] + 1;
			cur[i + 1] = 1;
		}
		if (cur[size - 1] != num[size - 1] - '0') ans++;
		printf("%d\n", ans);

	}
	return 0;
}