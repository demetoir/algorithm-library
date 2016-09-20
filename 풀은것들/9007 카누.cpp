//정렬, 배열검색, 투포인터
//처음에는 그냥 이분탐색으로 찾으려 했는데 시간초과
//그래서 투포인터로 풀었다

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

#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
#define MAX_N 1001
int student[4][MAX_N];
vector<LL>A, B;
int k, n;
LL ans = INF;
LL diff = INF;


int main() {
	int test = 0;
	si(test);
	for (; test > 0; test--) {
		si(k); si(n);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++)
				si(student[i][j]);
		}
		A.clear();
		B.clear();
		ans = diff = LLINF;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A.push_back(student[0][i] + student[1][j]);
				B.push_back(student[2][i] + student[3][j]);
			}
		}

		sort(all(A));
		sort(all(B));
		int index = B.size() - 1;
		for (int i = 0; i < A.size(); i++) {			
			while (1) {
				if (diff == abs(k - A[i] - B[index])) {
					ans = min(ans, A[i] + B[index]);
				}
				else if (diff > abs(k - A[i] - B[index])) {
					diff = abs(k - A[i] - B[index]);
					ans = A[i] + B[index];
				}

				if (A[i] + B[index] <= k || index == 0) 
					break;		
				index--;

			}

		}
		printf("%d\n", ans);

	}


	return 0;
}


