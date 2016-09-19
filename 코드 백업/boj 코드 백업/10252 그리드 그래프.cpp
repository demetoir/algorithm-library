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
#define MAX_N 1000

int memo1[2][31];
int memo2[2][31];


int n, m,ans;

int  main() {
	int testcase;
	for ( si(testcase) ; testcase > 0; testcase--) {
		si(m); si(n);
		int dx = 1;
		//¾Æ·¡ À§
		printf("1\n");
		if ( n%2 == 0) {
			for (int c = 0,i = 0,j = 0; c < m*n; c++) {
				printf("(%d,%d)\n", i, j);
				i += dx;
				if (i >= m || i < 0) {
					dx = -dx;
					i += dx;
					j++;
				}
			}
		}
		else if (m % 2 == 0){
			for (int c = 0, i = 0, j = 0; c < m*n; c++) {
				printf("(%d,%d)\n", i, j);
				j += dx;
				if (j >= n || j < 0) {
					dx = -dx;
					j += dx;
					i++;
				}
			}
		}
		else {
			for (int j = n - 1; j > 0; j--)
				printf("(%d,%d)\n", m-1, j);
			for (int i = m - 1; i >= 0; i--) 
				printf("(%d,%d)\n", i, 0);

			n--; m--;
			for (int c = 0, i = 0, j = 0; c < m*n; c++) {
				printf("(%d,%d)\n", i, j+1);
				i += dx;
				if (i >= m || i < 0) {
					dx = -dx;
					i += dx;
					j++;
				}
			}

		}

	}

	printf("%d\n", ans);
	return 0;
}










