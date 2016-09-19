#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N 10000
#define si(a) scanf("%d",&(a))


int sorted[MAX_N + 1];
int n;


int main() {
	si(n);
	for (int i = 0, val; i < n; i++) {
		si(val);
		sorted[val+3000] = 1;
	}
	for (int i = 0; i <= MAX_N; i++) {
		if (sorted[i])
			printf("%d ", i-3000);
	}
	printf("\n");

	return 0;
}