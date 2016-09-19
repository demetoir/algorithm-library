#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>



#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)? (a):(b))


#define forn(i,n) for(int i=0;i<n;i++)
#define for_se(i,start,end) for(int i=start;i<end;i++)


int main() {
	int T;
	scanf("%d", &T);
	while (T>0) {
		T--;


		int a, b,c;
		int A, B, C;
		int AB, BC, CA;
		int d;
		scanf("%d %d %d %d %d %d", &A, &B, &C, &AB, &BC, &CA);
		int ans = 0;
		int val = 0;
		forn(i, A+1) {
			forn(j, B+1) {
				if (i <= A && (i + j) <= B && j <= C) {
					a = A - i;
					b = B - i - j;
					c = C - j;
					d = MIN(a, c);
					val = i* AB + j* BC + d* CA;
					ans = MAX(ans, val);
				}
				else { break; }
			}

		}
		printf("%d\n", ans);

	}



}
