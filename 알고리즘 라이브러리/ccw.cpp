//ccw
//세점을 이었을떄 반시계방향인지 시계방향인지 직선인지 판별
//
//시간 복잡도 O(1)
//
//참고 자료
//http://blog.naver.com/PostView.nhn?blogId=kaheeyah&logNo=220592648266&parentCategoryNo=60&categoryNo=174&viewDate=&isShowPopularPosts=false&from=postView
//http://cookyworld.tistory.com/49
//
//문제
//11758 ccw https://www.acmicpc.net/problem/11758

#include <utility>
#define pii pair<int,int>
using namespace std;
//P1, P2, P3를 순서대로 이은 선분이 반시계 방향을 나타내면 1, 시계 방향이면 -1, 일직선이면 0
int x[3];
int y[3];
int ccw(int x[3],int y[3]) {
	int ret = 0;
	ret = (x[0] * y[1] + x[1] * y[2] + x[2] * y[0]) - (x[0] * y[2] + x[1] * y[0] + x[2] * y[1]);

	if (ret < 0) ret = -1;
	if (ret > 0) ret = 1;
	return ret;
}


int ccw(pii p1, pii p2, pii p3) {
	return (p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first);
}

struct P {
	int x, y;
};
int ccw(P p1, P p2, P p3) {
	return (p1.x*p2.y + p2.x*p3.y + p3.x *p1.y) - (p1.x*p3.y + p2.x *p1.y + p3.x * p2.y);
}