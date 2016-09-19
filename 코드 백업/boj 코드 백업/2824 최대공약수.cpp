#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define si(a) scanf("%d",&(a))
#define MAX_SIZE 1000
#define MOD 1000000000
int A[MAX_SIZE]; 
int B[MAX_SIZE];
int n, m;

map<int, int> amap, bmap;
vector <int> prime;
#define SEIVE_SIZE 1000000
int seive[SEIVE_SIZE];
long long  ans;

void makePrime() {
	for (int i = 2; i < SEIVE_SIZE; i++) {
		if (seive[i] >= 1) continue;
		prime.push_back(i);
		for (int j = i ; j < SEIVE_SIZE; j += i)
			seive[j] = i;
	}
}

void addMap(map<int, int> &iimap, int k) {
	bool flag = false;
	while (k!=1) {
		flag = false;
		for (int i = 0,p; i < prime.size(); i++) {
			p = prime[i];
			if (k%p == 0) {
				k = k / p;
				iimap[p]++;
				flag = true;
				break;
			}
			if (p*p > k)break;
		}
		if (flag == false) {
			iimap[k]++;
			break;
		}	
	}
}


int main() {
	makePrime();
	si(n);
	for (int i = 0,val; i < n; i++) {
		si(val);
		addMap(amap, val);
	}
	si(m);
	for (int i = 0,val; i < m; i++) {
		si(val);
		addMap(bmap, val);
	}
	ans = 1;
	bool flag = false;
	map < int, int>::iterator iter;
	for (iter = amap.begin(); iter != amap.end(); iter++) {
		int val = iter->first;
		int count = iter->second;

		if (bmap.find(val) != bmap.end()) {
			int mulSize = min(count, bmap[val]);
			for (int i = 0; i < mulSize; i++) {
				if (ans *val > MOD) flag = true;
				ans = (ans * val) % MOD;
			}
		}
	}
	if (flag) {
		int val = ans;
		int count = 0;
		while (1) {
			if (val == 0)break;
			count++;
			val = val / 10;
		}
		for (int i = 0; i < 9 - count; i++)
			printf("0");
	}
	if (ans != 0)
		printf("%d\n", ans);
	
	return 0;
}