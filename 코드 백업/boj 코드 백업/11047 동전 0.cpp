#include <vector>
#include <stdio.h>
using namespace std;

#define si(a) scanf("%d",&(a))
#define FORI(n) for(int i =0; i<n;i++)

int n, k;
vector< int> coin;

int main() {
	si(n); si(k);
	FORI(n) {
		int val;
		si(val);
		coin.push_back(val);
	}
	int ans = 0;
	for (int i = coin.size() - 1; i >= 0; i--) {
		if (coin[i] > k) { continue; }
		ans += k / coin[i];
		k = k % coin[i];

	}

	printf("%d\n", ans);
	return 0;
}