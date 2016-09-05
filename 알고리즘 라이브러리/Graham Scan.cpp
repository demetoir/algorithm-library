//Graham scan (그라함 스캔)
//
//시간 복잡도 O(nlog(n))
//
//선행조건
//ccw 를 알고있어야함
//
//참고자료
//http://hns17.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-ConvexHull-Grahams-Scan
//http://www.slideshare.net/ssuser88a8b3/2-57761427
//http://blog.myungwoo.kr/104
//
//문제
//
//10254 고속도로 https://www.acmicpc.net/problem/10254

#include <stack>
#include <utility>
#include <algorithm>

using namespace std;
#define MAX_N 100000
#define pii pair<int,int>
struct P{
	int x,y;
};
int ccw(P p1, P p2, P p3) {
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

P points[MAX_N];
P convex_hull[MAX_N];
P startp , tempp;

int n;
bool cmp(P a, P b) {
	return ccw(tempp,startp,a) < ccw(tempp,startp,b);
}

void Graham_scan() {
	//find start point
	sort(points, points + MAX_N);
	P startp = points[0];
	P tempp = startp;
	tempp.x += 10;

	//compute degree from other point and sort
	sort(points + 1, points + MAX_N, cmp);

	//make convex_hull
	stack<P>st;
	st.push(points[0]);
	st.push(points[1]);

	for (int i = 2; i < n; i++) {
		P p2 = st.top(); st.pop();
		P p1 = st.top();

		//반시계방향일떄까지 stack에서 pop함
		while (ccw(p1, p2, points[i]) < 0) {
			p2 = st.top(); st.pop();
			p1 = st.top();
		}
		

	}



}



