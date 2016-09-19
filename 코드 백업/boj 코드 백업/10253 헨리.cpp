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
#define LLINF (((LL)1)<<63  -1)
#define AND &&
#define OR ||

//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 20
int tree[MAX_N];
int n;
int m;
LL maxans = 0;
LL minans = LLINF;

char str[MAX_N];
int num[10];
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int a, b;
int main() {
	int test;
	si(test);
	for (; test > 0; test--) {
		si(a);
		si(b);



		while (a > 1) {
			int mul = (int)ceil(b / double(a));
			a = a*mul - b;
			b = mul*b;
			int div = gcd(a, b);
			if (div > 1) {
				a /= div;
				b /= div;
			}
		}
		
		printf("%d\n", b);
	
	}

	return 0;
}




