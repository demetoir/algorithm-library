#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sf(a) scanf("%f",&(a))
#define LL long long
#define MOD 1000000000
#define PRIME_SIZE 8
#define MAX_N 1000000

int memo[MAX_N + 1];

int main() {
	int index = 0;
	for (int i = 1; i < 1234; i++) {
		for (int j = 0; j < i; j++) {
			if (index >= MAX_N + 1) break;
			memo[index] = i;
			index += 1;
		}
	}
	int a, b;
	si(a); si(b);
	int sum = 0;
	for (int i = a-1; i <= b-1; i++) {
		sum += memo[i];
	}
	printf("%d\n", sum);

	return 0;
}