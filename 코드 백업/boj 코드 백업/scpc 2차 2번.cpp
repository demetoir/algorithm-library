#include <cstdio>
#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

#define MAX(a,b) (((a)>(b))? (a):(b))
#define MIN(a,b) (((a)<(b))? (a):(b))
#define ABS(a) (((a)<(0))? (-(a)):(a))
#define ll long long
#define si(a) scanf("%d",&a)

using namespace std;
int n, m, k;
int memo[10001][3];
int p[10001], q[10001];
void init() {
	for (int i = 0; i < 10001; i++) {
		memo[i][0] = -1;
		memo[i][1] = -1;
		memo[i][2] = -1;
		p[i] = 0;
		q[i] = 0;
	}
}
int main(int argc, char** argv) {
	/* 아래 freopen 함수는 sample_input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 sample_input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 sample_input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 sample_input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("sample_input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		init();
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		si(n);
		for (int i = 0; i < n; i++) {
			int a;
			si(a);
			p[i + 1]=a; 
		}
		for (int i = 0; i < n; i++) {
			int a;
			si(a);
			q[i + 1] = a;
		}

		memo[0][0] = 0;
		memo[0][1] = 0;
		memo[0][2] = 0;
		for (int i = 1; i <= n; i++) {
			//x
			memo[i][0] = MAX(memo[i][0], memo[i - 1][0]);
			memo[i][0] = MAX(memo[i][0], memo[i - 1][1]);
			memo[i][0] = MAX(memo[i][0], memo[i - 1][2]);


			//p
			memo[i][1] = MAX(memo[i][1], memo[i - 1][0]);
			memo[i][1] = MAX(memo[i][1], memo[i - 1][1]+p[i]);
			memo[i][1] = MAX(memo[i][1], memo[i - 1][2]+p[i]);

			//q
			if (i - 2 <0) {
				memo[i][2] = MAX(memo[i][2], q[i]);
			}
			else {
				memo[i][2] = MAX(memo[i][2], memo[i - 2][0]);
				memo[i][2] = MAX(memo[i][2], memo[i - 2][1] + q[i]);
				memo[i][2] = MAX(memo[i][2], memo[i - 2][2] + q[i]);

			}

		}
		int ans = 0;
		ans = MAX(ans, memo[n][0]);
		ans = MAX(ans, memo[n][1]);
		ans = MAX(ans, memo[n][2]);



		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}