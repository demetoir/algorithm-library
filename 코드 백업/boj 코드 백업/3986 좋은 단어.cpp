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
#define LLINF ( (((LL)1) <<62)  -1)
#define AND &&
#define OR ||

#define FOR(i,s,e) for (int i = s; i<e; i++)
//////////////////////////////////////////////////////////////////////////////////


#define MAX_N 100001
char str[MAX_N];
int n;
int ans = 0;
stack <int> s;
int main() {
	si(n);
	for (int i = 0; i < n; i++) {
		ss(str);
		int size = strlen(str);
		s = stack<int>();
		for (int i = 0; i < size; i++) {
			if (str[i] == 'A') {
				if (s.empty() || s.top() == 'B') {
					s.push('A');
				}
				else if (s.top() == 'A') {
					s.pop();
				}
			}
			else{
				if (s.empty() || s.top() == 'A') {
					s.push('B');
				}
				else if (s.top() == 'B') {
					s.pop();
				}			
			}
		}
		if (s.empty()) ans += 1;

	}
	printf("%d\n", ans);
	return 0; 
}

