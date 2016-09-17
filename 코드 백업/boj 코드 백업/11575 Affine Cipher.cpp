#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

#define LL long long
#define MP pair < int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define sS(a) scanf("%s",a)
#define INF 1234567890
#define INFLL 12345678912345678

////////////////////////////////////////////////////////////////////////////////

int a, b;
char str[1000001];
int  main() {
	int testcase;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		memset(str, 0, sizeof(str));
		scanf("%d%d%s", &a, &b, str);
	
		for (int i = 0; str[i] != 0; i++) {
			str[i] = (((str[i] - 'A')*a + b) % 26) + 'A';
		}
		puts(str);
	}



	return 0;
}











