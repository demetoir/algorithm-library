#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <string.h>

#define ABS(a)       (a)<0?-(a):(a)
#define MAX(a,b)   (a)>(b)?(a):(b)
#define MIN(a,b)   (a)<(b)?(a):(b)
#define FOR(a,b,c)    for((a)=(b);(a)<=(c);(a)++)
#define _FOR(a,b,c)   for((a)=(b);(a)<(c);(a)++)
#define si(a)       scanf("%d", &(a))
#define si2(a,b)   scanf("%d %d",&(a),&(b))
#define si3(a,b,c)   scanf("%d %d %d", &(a), &(b), &(c))
#define ss(a)      scanf("%s", (a))
#define pi(a)      printf("%d\n", (a))
#define pc(a)      printf("%c\n",(a))
#define pii       pair<int, int>
#define MAX_N       1234
#define MAX_M      1234
#define INF         2e9
#define TRUE      1
#define FALSE      0

using namespace std;

char sen[100], words[51][51];
int dif[51][51], mem[51];
int l, n;

int diff(int pos, int nstr, int len) {
	int i, cnt = 0;
	int st[40], ed[40];
	_FOR(i, 0, 40)
		st[i] = ed[i] = 0;
	_FOR(i, 0, len) {
		st[words[pos][i] - 'a']++;
		ed[sen[nstr + i] - 'a']++;
		if (words[pos][i] != sen[nstr + i])
			cnt++;
	}

	_FOR(i, 0, 40)
		if (st[i] != ed[i])
			return -1;
	return cnt;
}

int fun(int end) {
	if (mem[end] < INF) return mem[end];

	int i;

	_FOR(i, 0, n) {
		int len = strlen(words[i]);
		if (len <= end)
		{
			int temp = diff(i, end - len, len);
			if (temp != -1) {
				//printf("%d -> %d\n",end, temp);
				mem[end] = MIN(mem[end], temp + fun(end - len));
			}
		}
	}
	return mem[end];
}

int main() {
	ss(sen);
	int i, j, k;
	si(n);
	l = strlen(sen);

	_FOR(i, 0, 51)
		_FOR(j, 0, 51) dif[i][j] = INF;

	_FOR(i, 0, 51)
		mem[i] = INF;
	mem[0] = 0;

	_FOR(i, 0, n)
		ss(words[i]);

	int t = fun(l);
	if (t != INF)
		pi(t);
	else printf("-1");
	return 0;
}