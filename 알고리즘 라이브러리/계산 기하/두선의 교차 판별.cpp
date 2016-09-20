//두선의 교차판별
//직선과 직선의 교차 판별
//선분과 선분의 교차 판별 
//교차점 위치 구하기
//
//
//참고 자료
//
//http://bowbowbow.tistory.com/17
//http://3dmpengines.tistory.com/786
//
//문제
//
//
//10255
//
//
#include <math.h>
#include <algorithm> 
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


//a->b 로가는 직선과 c->d 로 가는 직선의 교차를 판별하고 교차하면 x에 교차점을 반환한다
bool lineIntersection(vector2 a, vector2 b,
	vector2 c, vector2 d, vector2 &x) {
	double det = (b - a).cross(d - c);
	if (fabs(det) < 1e-4)return false;
	//if (fabs(det) < EPSILON)return false;
	x = a+(b - a)*((c - a).cross(d - c) / det);
	return true;
}


double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}

bool parralledSegment(vector2 a, vector2 b,
	vector2 c, vector2 d, vector2& p) {
	if (b < a) swap(a, b);
	if (d < c) swap(d, c);

	if (ccw(a, b, c) != 0|| b < c || d < a) return false;

	if (a < c)p = c;
	else p = a;

	return true;
}

bool inbounding_ractangle(vector2 p, vector2 a, vector2 b) {
	if (b < a)swap(a, b);
	return p == a || p == b || (a < p && p < b);
}

//a->b 로가는 선분과 c->d 로 가는 선분의 교차를 판별하고 교차하면 p에 교차점을 반환한다
bool segmentIntersection(vector2 a, vector2 b,
	vector2 c, vector2 d, vector2 &p) {
	if (!lineIntersection(a, b, c, d, p))
		return parralledSegment(a, b, c, d, p);

	return inbounding_ractangle(p, a, b) &&
		inbounding_ractangle(p, c, d);
}

//a->b 로가는 선분과 c->d 로 가는 선분의 교차를 판별만한다
bool segmentIntersection(vector2 a, vector2 b,
	vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a)*ccw(c, d, b);

	if (ab == 0 && cd == 0){
		if (b < a)swap(a, b);
		if (d < c) swap(c, d);
		return !(b< c || d < a);
	}
	return ab <= 0 && cd <= 0;
}


//교차점 위치 구하지 않고 교차 하는지만 판단하는것 간단한버전..
//점벡터
struct P {
	int x, y;
	int s() { return this->x + this->y; }// wtf???
} B[4];

//선분 벡터
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

//0 :교차하지 않음 
//1: 한점에서 교차  
//-1: 여러점에서 교차(겹친다)
int insc(L p, L q) {
	//선분이 서로 한 직선위에 있을때
	if (!ccw(p.a, p.b, q.a) && !ccw(p.a, p.b, q.b)) {
		if (p.a.s() > p.b.s()) swap(p.a, p.b);
		if (q.a.s() > q.b.s()) swap(q.a, q.b);
		int a = p.a.s(), b = p.b.s(), c = q.a.s(), d = q.b.s();
		//서로 만나지 않음
		if (b < c || d < a) return 0;

		//선분간에 서로 끝점에서 만난다
		if (b == c || a == d) return 1;

		return -1;
	}

	//선분이 
	if (ccw(p.a, p.b, q.a) == ccw(p.a, p.b, q.b)
		|| ccw(q.a, q.b, p.a) == ccw(q.a, q.b, p.b))
		return 0;
	return 1;
}



