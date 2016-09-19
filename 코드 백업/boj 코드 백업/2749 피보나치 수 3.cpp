#include <stdio.h>
#include <map>

using namespace std;

#define  MOD  1000000

#define sll(a) scanf("%lld", &(a))
#define LL long long
LL n;
map<LL, LL> memo;
LL fib( LL k) {
	if (memo.find(k) != memo.end())
		return memo[k];
	LL ret = 0;

	LL a = fib(k / 2);
	LL b = fib(k / 2 + 1);
	if (k% 2 == 0)
		ret = a*( (b+b - a + MOD) % MOD);
	else
		ret = ((a*a) % MOD + (b*b) % MOD);
	memo[k] = (ret)%MOD;
	return memo[k];
}
int ans;
int main() {
	sll(n);
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 1;
	memo[3] = 2;
	ans = fib(n);
	printf("%d", ans);
	return  0;
}