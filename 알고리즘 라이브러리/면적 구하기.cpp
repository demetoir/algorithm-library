//면적 구하기
//점들의  집합으로 이루어지는 다각형의 면적을 구한다
#include <vector>
using namespace std;


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

double getarea(const vector<vector2> &p) {
	double ret = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1)&p.size();
		ret += p[i].x*p[j].y - p[j].x * p[i].y;
		//ret +=p[i].cross(p[j]);
	}
	return fabs(ret) / 2.0;
}


