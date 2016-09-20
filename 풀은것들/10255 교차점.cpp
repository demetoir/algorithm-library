//10255
//계산 기하 벡터,ccw
//계산 기하의 기초인 ccw 이다
//사각형의 선분을 따로 따로 ccw 먹인다
//근데 문제에서는 생각해야할 예외가 많다
//일단 사각형 꼭지점을 지날때 이때는 선분두개를 같이 지나게 된다
//선분의 끝점끼리 만났을때
//선분이 한직선 직선상에서 있고 서로  많은 점에서 교차할떄
//풀다가 답보고 배웠다

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

#include <math.h>
using namespace std;

int T;

struct P {
	int x, y;
	int s() { return this->x + this->y; }
} B[4];

struct L {
	L() {}
	L(const P &a, const P &b) : a(a), b(b) {}
	P a, b;
} A;

int ccw(const P &a, const P &b, const P &c) {
	int k = (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
	if (k > 0) return 1;
	if (k) return -1;
	return 0;
}

//0 교차 x 1점 교차  -1 여러점 교차
int insc(L p, L q) {
	if (!ccw(p.a, p.b, q.a) && !ccw(p.a, p.b, q.b)) {
		if (p.a.s() > p.b.s()) swap(p.a, p.b);
		if (q.a.s() > q.b.s()) swap(q.a, q.b);
		int a = p.a.s(), b = p.b.s(), c = q.a.s(), d = q.b.s();
		if (b < c || d < a) return 0;

		if (b == c || a == d) return 1;

		return -1;
	}

	if (ccw(p.a, p.b, q.a) == ccw(p.a, p.b, q.b)
		|| ccw(q.a, q.b, p.a) == ccw(q.a, q.b, p.b))
		return 0;
	return 1;
}

int main()
{
	int i;
	for (scanf("%d", &T); T--;) {
		scanf("%d%d%d%d", &B[0].x, &B[0].y, &B[2].x, &B[2].y);
		scanf("%d%d%d%d", &A.a.x, &A.a.y, &A.b.x, &A.b.y);
		B[1].x = B[2].x, B[1].y = B[0].y;
		B[3].x = B[0].x, B[3].y = B[2].y;

		int ans = 0;
		for (i = 0; i<4; i++) {
			//교차하는지 검사
			int v = insc(A, L(B[i], B[(i + 1) % 4]));
			if (v == -1) break;
			ans += v;

			//꼭지점에서 교차하는지 검사 
			//꼭지점에서 교차하면 두번 체크하니 따로 처리한다
			v = insc(A, L(B[i], B[i]));
			if (v) ans--;
		}
		printf("%d\n", i<4 ? 4 : ans);
	}
}