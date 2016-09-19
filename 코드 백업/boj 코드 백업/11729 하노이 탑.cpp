#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 100
#define si(a) scanf("%d",&(a))
#define MP pair<int,int>
#define LL long long
#define INF 9876543217654321
int n;
int ansn; 
void tower(int a,int b, int n) {
	if (n == 0) return;

	int other = 6 - a - b;

	tower(a, other, n - 1);

	printf("%d %d\n", a, b);

	tower(other, b, n - 1);

	return;
}
int main() {
	si(n);
	ansn = (1 << n) -1;
	printf("%d\n", ansn);

	tower(1, 3, n);

	return 0;
}