#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
#define si(a) scanf("%d",&(a))
#define MAX_N 100000

#define LL long long
#define MP pair < int, int>

LL ans;

int n, k;
int money[MAX_N];
stack < int > s;

int main() {
	int val, start;
	si(n);
	for (int i = 0,val; i < n; i++){
		si(money[i]);
	}


	for (int i = 0; i < n; i++) {
		while (!s.empty() && money[s.top()] > money[i]) {
			val = money[s.top()];
			s.pop();

			int day = i;
			if (!s.empty()) {
				day = (i - s.top() -1);
			}
			ans = max(ans, (LL)val*(LL)day);
		}
		s.push(i);
	}

	while (!s.empty()) {
		val = money[s.top()];
		s.pop();

		int day = n;
		if (!s.empty()) {
			day = (n - s.top() - 1);
		}
		ans = max(ans, (LL)val*(LL)day);
	}
		
	printf("%d\n", ans);
	return 0;
}