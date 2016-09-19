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
int n, m, k;
struct mp {
	mp(int x, int y) {
		a = x;
		b = y;
	}
	int a, b;
};
vector<mp> red, blue;

int main(int argc, char** argv) {

	setbuf(stdout, NULL);


	int T;
	int test_case;

	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
		si(n); 
		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		int a, b,c;
		red.clear();
		blue.clear();
		for (int i = 0; i < n; i++) {
			si(a); si(b); si(c);
			
			if (c == 0) {
				red.push_back(mp(a, b));
			}
			else {
				blue.push_back(mp(a, b));
			}			
		}


		int ans = 0;

		for (int i = 0; i < red.size(); i++) {
			int x, y; 
			x = red[i].a;
			y = red[i].b;
			int val = 0;
			for (int j = 0; j < red.size(); j++) {
				int a = red[j].a, b = red[j].b;
				if ((a >= x && b >= y) ||(a <= x && b <= y)) 
					val += 1;
				
			}
			for (int j = 0; j < blue.size(); j++) {
				int a = blue[j].a, b = blue[j].b;
				if ((a <= x && b >= y) || (a <= x && b >= y)) 
					val += 1;				
			}
			ans = MAX(ans, val);
		}

		for (int i = 0; i < blue.size(); i++) {
			int x = blue[i].a, y = blue[i].b;
			int val = 0;
			for (int j = 0; j < red.size(); j++) {
				int a = red[j].a, b = red[j].b;
				if ((a >= x && b >= y) || (a <= x && b <= y)) 
					val += 1;
				
			}
			for (int j = 0; j < blue.size(); j++) {
				int a = blue[j].a, b = blue[j].b;
				if ((a <= x && b >= y) || (a <= x && b >= y)) 
					val += 1;
				
			}
			ans = MAX(ans, val);
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}