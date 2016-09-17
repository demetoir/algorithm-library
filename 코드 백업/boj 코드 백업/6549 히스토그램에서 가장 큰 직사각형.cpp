#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
#define si(a) scanf("%d",&(a))
#define MAX_N 100000

#define LL long long


LL ans;

int n, k;
LL money[MAX_N];
stack < LL > s;

int main() {
	LL val, start,day;
	while (1) {
		si(n);
		if (n == 0)break;
		ans = 0;
		for (int i = 0, val; i < n; i++) 
			si(money[i]);
		
		for (int i = 0; i < n; i++) {
			while (!s.empty() && money[s.top()] > money[i]) {
				val = money[s.top()];
				s.pop();

				day = i;
				if (!s.empty()) {
					day = (i - s.top() - 1);
				}
				ans = max(ans, val*day);
			}
			s.push(i);
		}

		while (!s.empty()) {
			val = money[s.top()];
			s.pop();

			day = n;
			if (!s.empty()) {
				day = (n - s.top() - 1);
			}
			ans = max(ans, val*day);
		}

		printf("%lld\n", ans);
	}
	return 0;
}