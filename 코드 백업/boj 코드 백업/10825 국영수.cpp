#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define MP pair<int,int>
#define INF (1<<31 -1)
#define LLINF ( (((LL)1) <<63)  -1)
#define AND &&
#define OR ||

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 100001

int n;
int m;
LL maxans = 0;
LL minans = LLINF;

struct student {
	int a, b, c;
	char str[20];
};
bool mycmp (const student & A, const student & B) {
	if (A.a != B.a)return A.a > B.a;

	if (A.b != B.b)return A.b < B.b;

	if (A.c != B.c) return A.c > B.c;

	if (strcmp(A.str, B.str)<0) return true;

	return false;
}

vector<student> v;
int main() {
	student s;
	//char n[11], l, e, m;
	int n; scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%s %d %d %d", s.str, &s.a, &s.b, &s.c);
		v.push_back(s);
	}
	sort(v.begin(), v.end(), mycmp);
	for (int i = 0; i<n; i++) {
		printf("%s\n", v[i].str);
	}
	return 0;
}