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

#define SIZE 223
int N, K;
int a[223], p[223], f[223];
int s[223], e[233];
int work[101][101];

void init() {
	for (int i = 0; i < SIZE; i++) {
		a[i] = p[i] = f[i] = 0;
		s[i] = e[i] = 0;
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			work[i][j] = 0;
		}
	}
}
// work[T][i] T시간에 i번쨰 장인이 일을 했는가

struct shoe {
	shoe(int a,int b,int c) {
		left = a;
		finish = b;
		number = c;
	}
	int left;
	int finish;
	int number;
	
};
bool operator < (const shoe a,const shoe b) {
	if (a.finish == b.finish) {
		return a.left > b.left;
	}
	return a.finish > b.finish;
}

void find() {
	priority_queue < shoe > PQ;
	
	
	//시간
	for (int i = 0; i < 101;i++) {
		//구두
		for (int j = 0; j < N; j++) {
			if (a[j] <= i && i < f[j] && p[j] > 0) {
				PQ.push(shoe(p[j], f[j], j));
			}
		}
		while (!PQ.empty()) {
			int left, finish, number;
			left = PQ.top().left;
			finish = PQ.top().finish;
			number = PQ.top().number;
			PQ.pop();
			//printf("# %d %d %d\n", left,finish,number+1);

			//장인
			for (int k = 0; k < K; k++) {
				if (work[i][k] == 0 &&  s[k] <=i && i < e[k]) {
					//printf("## %d %d %d\n",i, number+1, k+1);
					p[number] -= 1;
					work[i][k] = 1;
					break;
				}
			}
		}
	}
}
int main(int argc, char** argv) {
	setbuf(stdout, NULL);

	int TC;
	scanf("%d", &TC);	// cin 사용 가능
	for (int test_case = 1; test_case <= TC; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오.	
		init();
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			int x, y, z;
			scanf("%d %d %d", &x, &y,&z);
			a[i] = x;
			f[i] = y;
			p[i] = z;
		}
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			s[i] = x;
			e[i] = y;
		}
		find();
		int ans = 1;
		for (int i = 0; i < N; i++) {
			if (p[i] != 0) {
				ans = 0;
			}
		}
		
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", ans);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}