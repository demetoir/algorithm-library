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


int K = 0;
unsigned long long maxans, minans;
int f(long long n , int k){
	
	if (k > K || n == 0) {
		return 0;
	}
	//printf("%lld %d\n", n, k);
	if (k == K && n != 1) {
		maxans = MAX(maxans, n);
		minans = MIN(minans, n);
	}
	

	f(n * 2, k + 1);
	if ((n - 1) % 3 == 0 ) {
		f((n - 1) / 3, k + 1);
	}
;
}

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC=64;
	scanf("%d", &TC);	// cin 사용 가능
	for (int test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		
		scanf("%d", &K);
		//K = test_case;
		int count = 0;
		maxans = 1;
		minans = 123456789;
		iimap.clear();
		if (K == 0) {
			printf("Case #%d\n", test_case);
			printf("1 1\n");
			continue;

		}
		for (int i = 2; i < 3000; i++) {
			//printf("##%d\n", i);
			int cur = i;
			bool isOK = true;
			for (int j = 0; j < K; j++) {
				//printf("##%d %d \n", i, cur);
				if (cur == 1 ) {
					isOK = false;
					break;
				}
				if (cur % 2 == 0) {
					cur = cur / 2;
				}
				else {
					cur = cur * 3 + 1;
				}
			}
			
			if (isOK == true &&cur == 1) {
				minans = i;				
				break;
			}
		}

		long long a = 1;
		maxans = 1;
		for (int i = 0; i < K; i++) {
			maxans = maxans * 2;
		}
		//f(1, 0);
		//cout << endl;
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능

		printf("%llu %llu\n", minans, maxans);
		//cout << endl;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}