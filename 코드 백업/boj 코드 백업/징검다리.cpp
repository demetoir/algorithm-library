#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <stack>
#include <string.h>

using namespace std;

vector<int> iv;
vector<int>::iterator iit;
vector<double> dv;
priority_queue <int> PQ;
queue <int>  Q;
map<int, string> istrmap;
map <long long, int>iimap;
struct mp {
	int a, b;
};
#define ABS(a)(((a) < (0))?-(a):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))



int N, K, L;
int bomb[50001];
int ans;
#define  MOD 1000000009
int dp1[101][50001];
int dp2[50001];
int f2(int cur);
int f1(int cur, int step);

int f1(int cur, int step) {
	int ret = dp1[step][cur]; 

	if (ret != -1)
		return ret;

	ret = f2(cur-step);

	if (cur - step >= 0 && bomb[cur - step] == 0) {
		int val = f1(cur - step, step);
		ret = (MOD+ret - val)%MOD;
	}
	ret = ret % MOD;
	dp1[step][cur] = ret;

	return ret;
}

int f2(int cur) {
	if (cur < 0)return 0;
	int ret = dp2[cur];

	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i <= K; i++) {
		if (bomb[cur] == 0) {
			int a = f1(cur, i);
			ret = (ret +a)%MOD;
		}
	}	
	ret = ret % MOD;
	dp2[cur] = ret;
	return ret;
}

void init() {
	for (int i = 1; i < N+1; i++) {
		dp2[i] = -1;
		for (int j = 0; j < K+1; j++) {
			dp1[j][i] = -1;
		}
	}

	for (int i = 0; i < 50001; i++) {
		bomb[i] = 0;
	}
	ans = 0;
	dp1[0][0] = 1;
	dp2[0] = 1;
	//for (int j = 0; j < K + 1; j++) {
	//	dp1[j][0] = 1;
	//}
	for (int i = 1; i < N + 1; i++) {
		dp1[0][i] = 0;
	}
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC;
	scanf("%d", &TC);	// cin 사용 가능
	for (int test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.	

		scanf("%d %d %d", &N, &K, &L);
		init();
		for (int i = 0; i < L; i++) {
			int a;
			scanf("%d", &a);
			bomb[a] = 1;
		}
		
		// 이 부분에서 정답을 출력하십시오.
		for (int i = 1; i < N+1 ; i++) {
			for (int j = 1; j < K +1 ; j++) {
				f1(i, j);
			}
		}

		printf("Case #%d\n", test_case);	// cout 사용 가능
		for (int i = 1; i < K +1; i++) {
			//printf("#%d\n", f1(N, i));
			ans = (f1(N, i)+ans)%MOD;
		}
		printf("%d\n", ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}