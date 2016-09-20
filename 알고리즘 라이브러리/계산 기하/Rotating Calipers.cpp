//rotating calipers 
//
//시간 복잡도 O(n)
//
//
//참고자료
//http://www.slideshare.net/ssuser88a8b3/2-57761427
//알고리즘 문제 해결 1권 참조
//
//
//문제
//
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
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


typedef vector<vector2> polygon;
//시계 반대 방향으로 주어진 볼록 다각형에서 가장 먼 꼭지점 쌍 사이의 거리를 반환한다
double rotating_calipers(const polygon &p) {
	int n = p.size();
	int left = min_element(p.begin(), p.end()) - p.begin();
	int right = max_element(p.begin(), p.end()) - p.begin();

	vector2 calipersA(0, 1);
	double ret = (p[right] - p[left]).norm();

	vector<vector2> toNext(n);
	for (int i = 0; i < n; i++) {
		toNext[i] = (p[(i + 1) % n] - p[i]).normalize();
	}
	int a = left, b = right;

	while (a != right || b != left) {
		double cosThetsA = calipersA.dot(toNext[a]);
		double cosThetsB = -calipersA.dot(toNext[b]);
		if (cosThetsA > cosThetsB) {
			calipersA = toNext[a];
			a = (a + 1) % n;
		}
		else {
			calipersA = -toNext[b];
			b = (b + 1) % n;
		}
		ret = max(ret, (p[a] - p[b]).norm());
	}
	return ret;
}