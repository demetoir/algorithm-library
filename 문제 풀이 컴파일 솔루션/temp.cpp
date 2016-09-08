
////10255
//
//#include <math.h>
//using namespace std;
//
//const double PI = 2.0 * acos(0.0);
//
//struct vector2 {
//	double x, y;
//	vector2(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}
//
//	bool operator == (const vector2 & rhs) const {
//		return x == rhs.x && y == rhs.y;
//	}
//
//	bool operator < (const vector2 & rhs) const {
//		return x != rhs.x ? x < rhs.x : y < rhs.y;
//	}
//
//	vector2 operator + (const vector2 &rhs)const {
//		return vector2(x + rhs.x, y + rhs.y);
//	}
//
//	vector2 operator - (const vector2 &rhs) const {
//		return vector2(x + rhs.x, y + rhs.y);
//	}
//
//	vector2 operator * (double rhs) const {
//		return vector2(x*rhs, y*rhs);
//	}
//
//	double norm()const { return hypot(x, y); }
//
//	vector2 normalize() const {
//		return vector2(x / norm(), y / norm());
//	}
//
//	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }
//
//	double dot(const vector2& rhs)const {
//		return x*rhs.y + rhs.x*y;
//	}
//
//	double cross(const vector2& rhs) const {
//		return x*rhs.y - rhs.x*y;
//	}
//	vector2 project(const vector2& rhs) const {
//		vector2 r = rhs.normalize();
//		return r * (r.dot(*this));
//	}
//};
//
//
//bool lineIntersection(vector2 a, vector2 b,
//	vector2 c, vector2 d, vector2 &x) {
//	double det = (b - a).cross(d - c);
//	if (fabs(det) < 1e-4)return false;
//	//if (fabs(det) < EPSILON)return false;
//	x = a + (b - a)*((c - a).cross(d - c) / det);
//	return true;
//}
//
//
//
//int  main() {
//	int test = 0;
//	si(test);
//	for (; test > 0; test--) {
//		int ans = 0;
//
//		int x1,y1, x2, y2;
//		si(x1);si(y1);si(x2);si(y2);		
//		vector2 a(x1,y1), b(x2,y2);
//		si(x1);	si(y1);	si(x2);	si(y2);
//		vector2 p;
//		vector2 r[4];
//		r[0] = vector2(x1, y1);
//		r[1] = vector2(x1, y2);
//		r[2] = vector2(x2, y2);
//		r[3] = vector2(x2, y1);
//
//		vector2 crossp(INF,INF);
//		for (int i = 0; i < 4; i++) {
//			if (lineIntersection(a, b, r[i],r[(i+1)%4], p) == true) {
//				if (crossp == vector2(INF, INF)) {
//					crossp = p;
//					ans += 1;
//				}
//				else if(crossp == p){
//					ans -= 1;
//				}
//			}
//		}
//
//
//		printf("%d\n", ans);
//
//	}
//	return 0;
//}
//
//