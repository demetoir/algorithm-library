//Graham scan (그라함 스캔)
//
//시간 복잡도 O(nlog(n))
//
//선행조건
//vector2 class 를 알아야한다
//ccw 를 알고있어야함
//벡터 외적을 하는데 있어서 오버 프로우가 있어날수있음
//
//참고자료
//http://hns17.tistory.com/entry/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-ConvexHull-Grahams-Scan
//http://www.slideshare.net/ssuser88a8b3/2-57761427
//http://blog.myungwoo.kr/104
//
//검증 완료
//문제
//1708 볼록 껍질
//
//10254 고속도로 https://www.acmicpc.net/problem/10254

// 이소스에서는 껍질을 만드는데 직선으로 만나는 점들은 포함하지 않는다
#include <stack>
#include <algorithm>
using namespace std;
#define LL long long
#define INF 2e9
#define MAX_N 100001
const double PI = 2.0 * acos(0.0);

struct vector2 {
	double x, y;
	vector2(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}

	bool operator == (const vector2 & rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator < (const vector2 & rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}

	vector2 operator + (const vector2 &rhs)const {
		return vector2(x + rhs.x, y + rhs.y);
	}

	vector2 operator - (const vector2 &rhs)const {
		return vector2(x - rhs.x, y - rhs.y);
	}

	vector2 operator * (double rhs) const {
		return vector2(x*rhs, y*rhs);
	}

	double norm()const { return hypot(x, y); }

	vector2 normalize() const {
		return vector2(x / norm(), y / norm());
	}

	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }

	double dot(const vector2& rhs)const {
		return x*rhs.y + rhs.x*y;
	}

	double cross(const vector2& rhs) const {
		return x*rhs.y - rhs.x*y;
	}
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};


LL ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

vector2 minp(INF, INF);
bool cmp(const vector2 a, const vector2 b) {
	vector2 A = a - minp;
	vector2 B = b - minp;
	if (ccw(A, B) > 0) return true;
	return false;
}

vector2 points[MAX_N];
int n;
int scan() {
	//가장 작은 점을 찾고 맨앞으로 보냄
	int minindex;
	for (int i = 0; i < n; i++) {
		if (minp.x > points[i].x ||
			minp.x == points[i].x && minp.y > points[i].y) {
			minp.x = points[i].x;
			minp.y = points[i].y;
			minindex = i;
		}
	}
	points[minindex] = points[0];
	points[0] = minp;

	// 나머지 점들을 기준점으로부터의 각도순으로 소트한다
	sort(points + 1, points + n, cmp);

	//스택으로부터 반시계 방향인 점들을 고른다
	stack <vector2> st;
	st.push(points[0]);
	st.push(points[1]);
	for (int i = 2; i < n; i++) {
		vector2 b = st.top(); st.pop();
		vector2 a = st.top();

		while (1) {
			LL val = ccw(points[i] - a, points[i] - b);
			if (val > 0) {
				st.push(b);
				st.push(points[i]);
				break;
			}
			else {
				if (st.size() == 1) {
					st.push(points[i]);
					break;
				}
				else {
					b = st.top(); st.pop();
					a = st.top();
				}
			}
		}
	}
	//st 이 convex hull 이 저정됨
	return st.size();
}

