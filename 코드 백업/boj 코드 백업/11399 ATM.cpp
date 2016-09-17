#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define si(a) scanf("%d" , &(a))


int n;
vector <int> p;
int ans = 0;
int main() {
	si(n);
	for (int i = 0,val; i < n; i++) {
		si(val);
		p.push_back(val);
	}
	sort(p.begin(), p.end());
	
	for (int i = 0,time = 0; i < n; i++) {
		time += p[i];
		ans += time;
	}
	printf("%d\n", ans);


	return 0;
}