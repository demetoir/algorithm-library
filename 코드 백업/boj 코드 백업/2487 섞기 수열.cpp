#include<stdio.h>

#define si(a) scanf("%d",&(a));
#define MAX_N 20000
#define LL long long

int seq[MAX_N + 1];
int n;
LL ans;

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a%b);
}

int main() {
	si(n);
	for (int i = 0;i < n; i++)	{
		si(seq[i]);
		seq[i] -=1;
	}
	ans = 1;
	for (int i = 0; i < n; i++) {
		if (seq[i] == -1)continue;
		int cur = seq[i];
		int len = 1;

		seq[i] = -1;
		while (seq[cur] != -1) {
			len += 1;
			int temp = seq[cur];
			seq[cur] = -1;
			cur = temp;
		}
		ans = (int)( ( ((LL)ans)*((LL)len) ) / (LL)gcd(ans, len) );

	}

	printf("%d\n", ans);
	return 0;
}