#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sf(a) scanf("%f",&(a))
#define LL long long
#define MOD 1000000000
#define PRIME_SIZE 8
#define MAX_N 1000

int ans;
int A[MAX_N];
int n;

vector <int> lis;



int main() {
	si(n);
	for (int i = 1; i <= n; i++)
		si(A[n -i]);


	lis.push_back(A[0]);
	
	for (int i = 1; i < n; i++) {
		int val = lower_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
		if (val >= lis.size())
			lis.push_back(A[i]);
		else {
			lis[val] = A[i];
		}
	}
	ans = lis.size();

	printf("%d\n", ans);

	return 0;
}