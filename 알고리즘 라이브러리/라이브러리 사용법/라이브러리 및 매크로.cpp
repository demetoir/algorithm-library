//밑에 매크로 사용법 있음
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <functional>
#include <limits>
#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
typedef long long LL;

#define INF 2e9
#define LLINF ( (LL)1e18 )

#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sll(a) scanf("%lld",&(a))
#define sc(a) scanf("%c",&(a))
#define ss(a) scanf("%s",a)
#define pii pair<int,int>
#define all(a) (a).begin(),(a).end()

int main() {
	//#define si(a) scanf("%d",&(a))
	int int_val;
	si(int_val);
	//scanf("%d",&(int_val))

	//#define slf(a) scanf("%lf",&(a))
	double double_val;
	slf(double_val);
	//scanf("%lf",&(double_val))

	//#define sll(a) scanf("%lld",&(a))
	LL LL_val;
	sll(LL_val);
	//scanf("%lld",&(LL_val))


	//#define sc(a) scanf("%c",&(a))

	char char_val;
	sc(char_val);
	//scanf("%c",&(char_val))

	//define ss(a) scanf("%s",a)
	char str[1000];
	ss(str);
	//scanf("%s",(str))

	//#define all(a) (a).begin(),(a).end()
	vector<int>vi;
	sort(all(vi));
}