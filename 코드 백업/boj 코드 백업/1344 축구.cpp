#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define si(a) scanf("%d",&(a))
#define LL long long
#define MOD 1000000000
#define PRIME_SIZE 8

#define slf(a) scanf("%lf",&(a))
#define sf(a) scanf("%f",&(a))

double p1, p2;
LL comb[20][20];
int prime[PRIME_SIZE] = { 2,3,5,7,11,13,17,19 };
int seive[20];
int n = 18;

double ans;
double memo[20][20][20];
double f(int count,int a, int b) {
	if (memo[count][a][b] != -1)
		return memo[count][a][b];

	if (count == 18){
		if (seive[a] == 1 || seive[b] == 1)
			return 1;
		return 0;
	}

	double ret = 0;
	ret += p1*p2*f(count + 1, a + 1, b + 1);
	ret += p1*(1-p2)*f(count + 1, a + 1, b);
	ret += (1-p1)*p2*f(count + 1, a , b+1);
	ret += (1-p1)*(1-p2)*f(count + 1, a, b);

	memo[count][a][b] = ret;

	return ret;
}

int main() {

	for (int i = 0; i < PRIME_SIZE; i++)
		seive[prime[i]] = 1;


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++){
			for (int k = 0; k < 20; k++){
				memo[i][j][k] = -1;
			}
		}
	}

	slf(p1); slf(p2);
	p1 = p1 / 100.0;
	p2 = p2 / 100.0;
	
	ans = f(0, 0, 0);

	printf("%.12lf\n", ans);
	return 0;
}