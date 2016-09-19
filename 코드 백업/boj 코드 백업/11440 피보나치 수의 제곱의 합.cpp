#include <stdio.h>
#include <map>

using namespace std;
#define LL long long 
map< int, int> memo;

#define MOD 1000000007

LL fib(LL n) {
	
	if (memo.find(n) != memo.end()) {
		return memo[n];
	}
	LL ret = 0;

	LL a = fib(n / 2);
	LL b = fib(n / 2 + 1);
	if (n % 2 == 1) {
		ret = (a*a) % MOD + (b*b) % MOD;
	}
	else {
		ret = (a*( (2 * b - a +MOD) %MOD ) ) % MOD;
	}
	memo[n] = ret%MOD;
	return memo[n];
}
int main(){
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 1;
	memo[3] = 2;
	LL n;
	scanf("%lld", &n);
	int ans = (fib(n)*fib(n + 1))%MOD;
	printf("%d", ans);
	return 0;
}
