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

#define MAX(a,b) (((a)>(b))? (a):(b))
#define MIN(a,b) (((a)<(b))? (a):(b))
#define ABS(a) (((a)<(0))? (-(a)):(a))
#define ll long long
#define si(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)

using namespace std;
int n, m,k;
struct rect {
	ll a, b, x, y;
	rect(ll a1,ll b1, ll a2,ll b2){
		a = a1;
		b = b1;
		x = a2;
		y = b2;
	}
};
#define MAX_N 5001
#define MULVAL 10000000
struct mp {
	ll a,b;
	int index;
	mp(ll x,ll y,int i){
		a = x;
		b = y;
		index = i;
	}

};
bool operator< (const mp A, const mp B) {
	if (A.a == B.a) {
		return A.b < B.b;
	}
	return !(A.a < B.a);
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
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		si(n); si(m); si(k);
		//vector<rect> v;
		vector<mp> v;
		for (int i = 0; i < k; i++) {
			int a, b, c, d;
			sll(a); sll(b); sll(c); sll(d);
			v.push_back(mp(a*MULVAL + b , c*MULVAL +d,i+1));
			
		}
		sort(v.begin(), v.end());


		vector <ll> lis;
		lis.push_back(v[0].b);

		for (int i = 1; i < k; i++) {
			int val = v[i].b;
			if (lis.back() <= val ) {
				lis.push_back(val);
			}
			else {
				vector<ll>::iterator it = lower_bound(lis.begin(), lis.end(), val);
				*it = val;
			}
		}

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.

		printf("Case #%d\n", test_case);
		printf("%d\n", lis.size());
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}