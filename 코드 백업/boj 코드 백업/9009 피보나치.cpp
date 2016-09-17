#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>

using namespace std;

#define LL long long
#define MP pair < int,int>
#define si(a) scanf("%d",&(a))
#define sLL(a) scanf("%lld",&(a))
#define INF 1234567890
#define INFLL 12345678912345678

#define MAX_N 1000
int memo[MAX_N + 1][MAX_N + 1];
int n, m;
vector<int> ans;
int fib[50];
int find(int n,int index) {
	int  ret=0;
	if (index == 0) {
		if (n == 0) {
			for (int i = ans.size()-1; i >=0; i--) {
				printf("%d ", ans[i]);
			}
			printf("\n");
			return 1;
		}
		else
			return 0;
	}
	if (fib[index] > n) {
		return find(n, index - 1);
	}
	int size = ans.size();
	ans.push_back(0);
	for (int i = index; i >= 0; i++) {
		ans[size] = fib[index];
		if (find(n - fib[index], i))
			return 1;
	}
	ans.pop_back();

	return 0;
}

int  main() {
	fib[1] = 1;
	for (int i = 2; i < 47; i++) 
		fib[i] = fib[i - 1] + fib[i - 2];


	int testcase;
	si(testcase);
	for (int test = 0; test < testcase; test++) {
		si(n);
		ans.clear();
		find(n, 46);
	}
	return 0;
}












