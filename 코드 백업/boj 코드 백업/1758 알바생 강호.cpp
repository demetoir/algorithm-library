#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define si(a) scanf("%d", &(a))

int n;
vector <int> p;
long long ans = 0;
long long val;

int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		si(val);
		p.push_back(val);
	}
	sort(p.rbegin(),p.rend());

	for (int i = 0; i < n; i++) {
		if (p[i] - i > 0)
			ans += (long long) (p[i] - i);
		//printf("%d %d %d\n",p[i],i, p[i] - i);
	}
	printf("%lld\n", ans);


 	return 0;
}