

#include <stdio.h>
#include <iostream>

#include <vector>
#include <queue>
#include <stack>
#include <map>

#include <algorithm>
#include <functional>
#include <limits>

#include <string>
#include <string.h>
#include <math.h>
#include <stdlib.h>

using namespace std;
typedef long long LL;


#define INF 2e9
#define LLINF ((LL)1e18)

#define si(a) scanf("%d",&(a))
#define slf(a) scanf("%lf",&(a))
#define sll(a) scanf("%lld",&(a))
#define sc(a) scanf("%c",&(a))
#define ss(a) scanf("%s",a)

#define MP pair<int,int>
#define pii pair<int,int>
//////////////////////////////////////////////////////////////////////////////////////////
pair<int, long long> p;
pair<int, pair< int, int> > tuple;
struct cid {
	int x;
	int y;
};

#define MAX_N 1001 // 10^3
int n;
int A[MAX_N];
vector <int> v_int;

vector <double> V_double;
queue <int> q;
queue< pair<int, int> > pairq;

//Á¤Á¡ °¹¼ö 10^5
//°£¼± °¹¼ö 10^7
#define MAX_V 100000
vector<int> G[MAX_V];
//

//vector < vector<int> > G3;
//int G2[MAX_V][MAX_V];

int main() {
	q.push(1);
	//pair<int, int> temp;
	//temp.first = 1;
	//temp.second = 2;

	pairq.push( MP(1,2) );
	
	int temp = q.front();
	q.pop();
	
	MP tempp = pairq.front();
	q.pop();

	int x = pairq.front().first;
	int y = pairq.front().second;
	q.pop();
	
	
	
	
	
	
	
	si(n);
	for (int i = 0; i < n; i++) {
		si(A[i]);
	}

	for (int i = 0; i < n; i++) {
		int val;
		si(val);
		v_int.push_back(val);
	}

	v_int.size();
	//v_int = {}
	v_int.push_back(123);
	//v_int  = {123}
	v_int.push_back(4);
	//v_int  = {123,4}

	int v, e;
	si(v);
	si(e);
	
	for (int i = 0; i < e; i++) {
		int a, b;
		si(a); si(b);
		G[a].push_back(b);
		G[b].push_back(a);
		//G[a] = {b,}
		//G[b] = {a,}
	}

	char str[10000];
	ss(str);
	int size = strlen(str);

	for (int cur = 0; cur < v; cur++) {
		for (int j = 0; j < G[cur].size(); j++) {
			int next = G[cur][j];
			//cur->next
		}
	}

	for (int i = 0; i < MAX_V; i++) {
		G[i].clear();
	}
	//ST
	//v_int.assign(n, ST(0,1) );
	return 0;
}
