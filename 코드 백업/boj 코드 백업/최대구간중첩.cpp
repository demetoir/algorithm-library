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

vector<char> v;
priority_queue <int> PQ;
queue <int>  Q;
map<int, string> istrmap;
int cmp(const void* a, const void* b) {
	return a > b;
}
struct myPair {
	myPair(int _a, int _b) {
		a = _a;
		b = _b;
	}
	int a, b;
};
bool operator < (const myPair A, const myPair B) {
	if (A.a == B.a) {
		return A.b < B.b;
	}
	return !(A.a < B.a);
}
int a[12] = { 4,3,2,1,0, };

int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC;
	scanf("%d", &TC);	// cin 사용 가능
	for (int test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.
		vector <myPair> v;
		int a, b;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			v.push_back(myPair(a, b));
		}
		sort(v.begin(), v.end());
		//printf("\n");
		//for (int i= 0; i < n; i++) {
		//	printf("%d %d\n", v[i].a, v[i].b);
		//}
		vector <int> lis;
		lis.push_back(v[0].b);

		for (int i = 1; i < n; i++) {
			int val = v[i].b;
			if (lis.back() <= val) {
				lis.push_back(val);
			}
			else {
				vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), val);
				*it = val;
			}
		}
		//printf("\n");
		//for (int i = 0; i < lis.size(); i++) {
		//	printf("%d ", lis[i]);
		//}
		//printf("\n");
		//printf("\n");

		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", lis.size());
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}