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

struct vector2 {
	double x, y;
	vector2(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}

	bool operator == (const vector2 & rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	//bool operator < (const vector2 & rhs) const {
	//	return x != rhs.x ? x < rhs.x : y < rhs.y;
	//}

	vector2 operator + (const vector2 &rhs)const {
		return vector2(x + rhs.x, y + rhs.y);
	}

	vector2 operator - (const vector2 &rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}

	//vector2 operator * (double rhs) const {
	//	return vector2(x*rhs, y*rhs);
	//}

	//double norm()const { return hypot(x, y); }

	//vector2 normalize() const {
	//	return vector2(x / norm(), y / norm());
	//}

	//double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }

	//double dot(const vector2& rhs)const {
	//	return x*rhs.y + rhs.x*y;
	//}

	double cross(const vector2& rhs) const {
		return x*rhs.y - rhs.x*y;
	}
	//vector2 project(const vector2& rhs) const {
	//	vector2 r = rhs.normalize();
	//	return r * (r.dot(*this));
	//}
};

double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}