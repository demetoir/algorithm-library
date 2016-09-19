#include <stdio.h>
#include <vector>
using namespace std;


#define si(a) scanf("%d",&(a))
#define MAX_N 1001
#define MAX(a,b) ( (a)>(b) ? (a):(b) )

int n;
int ans;
int memo[MAX_N][MAX_N];
int value[MAX_N];
int init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memo[i][j] = -1;
		}
	}
}
int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		si(value[i]);
	}
	memo[0][0] = 0;








	printf("%d", ans);
	return 0;


}