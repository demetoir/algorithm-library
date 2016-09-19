#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sf(a) scanf("%f",&(a))
#define LL long long
#define MOD 1000000000
#define PRIME_SIZE 8
#define MAX_N 1000

int ans;
int A[MAX_N];
int n;

int find(int index) {
	int ret = 1;
	int mid = A[index];
	vector <int> leftlis,rightlis;


	for (int i = 0; i < index; i++) {
		if (mid <= A[i]) continue;

		if (leftlis.size() == 0) {
			leftlis.push_back(A[i]);
			continue;
		}

		int val = lower_bound(leftlis.begin(), leftlis.end(), A[i]) - leftlis.begin();
		if (val >= leftlis.size())
			leftlis.push_back(A[i]);
		else {
			leftlis[val] = A[i];
		}
	}

	for (int i = n-1; i>index; i--) {
		if (mid <= A[i]) continue;

		if (rightlis.size() == 0) {
			rightlis.push_back(A[i]);
			continue;
		}
		int val = lower_bound(rightlis.begin(), rightlis.end(), A[i]) - rightlis.begin();
		if (val >= rightlis.size())
			rightlis.push_back(A[i]);
		else {
			rightlis[val] = A[i];
		}
	}

	ret += rightlis.size() + leftlis.size();	
	return ret;
}


int main() {
	si(n);
	for (int i = 0; i < n; i++)
		si(A[i]);
	
	for (int i = 0; i < n; i++) {
		ans = max(find(i), ans);
	}

	printf("%d\n", ans);


	return 0;
}