#include <stdio.h>

#include <math.h>

using namespace std;
#define sll(a) scanf("%lld",&(a))

#define ll long long

int getgcd(ll p, ll q)
{
	if (q == 0) return p;
	return getgcd(q, p%q);
}

int main() {
	ll lcm, gcd;
	sll(gcd), sll(lcm);
	ll val = lcm / gcd;
	ll sum = 123456789000;
	ll ans;

	for (ll i = 1; i<= val; i++) {
		if (val % i > 0) continue;

		//if (i + val / i > sum)break;

		if (i + val / i < sum && getgcd(i,val/i) == 1) {
			ans = i;
			sum = i + val / i;
		}
	}

	printf("%lld %lld\n", gcd * ans, gcd * (val / ans));

	return 0;
}