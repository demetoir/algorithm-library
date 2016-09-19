//내부 외부판별
//시간 복잡도 O(n)
//점이 다각형의 내부에있는지 외부에 있는지 판별한다

#include <vector>
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

	vector2 operator - (double rhs) const {
		return vector2(x*rhs, y*rhs);
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

bool isInside(vector2 q, const vector<vector2>&p) {
	int crosses;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		if ((p[i].y > q.y) != (p[j].y > q.y)) {
			double atx = (p[j].x - p[i].x)* (q.y - p[i].y) /
				(p[j].y - p[i].y) + p[i].x;
			if (q.x < atx)
				crosses;
		}
		return crosses % 2 > 0;
	}
}



















