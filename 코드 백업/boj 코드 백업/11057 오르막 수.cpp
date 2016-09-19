#include <stdio.h>
#include <vector>
using namespace std;
int memo1[10];
int memo2[10];
#define MOD 10007

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 10; i++) {
		memo1[i] = 1;
	}

	for (int iter = 1; iter < n; iter++) {

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (j >= i) {
					memo2[j] = (memo2[j] + memo1[i]) % MOD;
				}
			}
		}

		for (int i = 0; i < 10; i++) {
			memo1[i] = memo2[i];
			memo2[i] = 0;
		}
	}
	int ans=0;
	for (int i = 0; i < 10; i++) {
		ans += memo1[i];
	}
	printf("%d", ans%MOD);

	return 0;
}