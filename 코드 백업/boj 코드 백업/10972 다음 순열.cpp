#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

#define LL long long
#define si(a) scanf("%d",&(a))
#define sf(a) scanf("%f",&(a))
#define sLL(a) scanf("%lld",&(a))
#define ss(a) scanf("%s",a)
#define MP pair<int,int>
#define INF (1<<31 -1)
#define LLINF (((LL)1)<<63  -1)
//////////////////////////////////////////////////////////////////////////////////
#define MAX_N 10001
#define BIT_MAX (1<<20)



int n;
bool isfind = false;
vector<int> ans;

vector < int> num(MAX_N);
int main() {
	si(n);
	for (int i = 0; i < n; i++)
		si(num[i]);
	int start = -1;
	for (int i = 0; i<n-1; i++) {
		if (num[i] < num[i + 1])
			start = i;	
	}

	if (start == -1) {
		printf("-1");
		return 0;
	}

	int val = INF;
	int index = 0;
	for (int i = start + 1; i < n; i++) {
		if (num[start] < num[i] && num[i] < val) {
			val = num[i];
			index = i;
		}
	}
	int temp = num[start];
	num[start] = num[index];
	num[index] = temp;
	for (int i = start + 1; i < n; i++)
		ans.push_back(num[i]);	

	sort(ans.begin(), ans.end());

	for (int i = 0; i <= start; i++)
		printf("%d ", num[i]);

	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);

	printf("\n");
	return 0;
}




