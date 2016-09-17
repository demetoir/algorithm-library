#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

#define si(a) scanf("%d",&(a))
#define LL long long
#define MOD 1000000000
int w[10],k[10];

int main() {
	for (int i = 0; i < 10; i++) 
		si(w[i]);
	for (int i = 0; i < 10; i++)
		si(k[i]);
	sort(k, k + 10);
	sort(w, w + 10);

	int a, b;
	a = w[9] + w[8] + w[7];
	b = k[9] + k[8] + k[7];

	printf("%d %d\n", a, b);
	return 0;
}