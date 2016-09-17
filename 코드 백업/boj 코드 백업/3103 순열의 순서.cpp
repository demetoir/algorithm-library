#include <stdio.h>
#include <vector>
using namespace std;
#define si(a) scanf("%d",&(a))
#define MAX_N 100000
#define MOD 1000000007
#define MAX_K 300000
#define LL long long
#define MP pair < int, int>

int seq[MAX_K + 1];
int ans[MAX_N];
int factorial[MAX_K + 1];
int mulval[MAX_K + 1];
int A[MAX_K + 1];
int B[MAX_K + 1];


vector < int > seqtree;
vector < int > midsumtree;
vector < MP > query[MAX_K+1];
vector < int > midsum[MAX_K + 1];

int n, k;
int	seq_rank = 0;


int sum(vector <int> &tree, int index) {
	int ret = 0;
	while (index > 0) {
		ret = (ret + tree[index])%MOD;
		index -= (index & -index);
	}
	return ret;
}

void update(vector <int> &tree, int index, int diff) {
	while (index < tree.size()) {
		tree[index] = (tree[index]+ diff)%MOD;
		index += (index & -index);
	}
}

void make_factorial() {
	factorial[0] = 1;
	for (int i = 1; i < MAX_K; i++) {
		factorial[i] = (int)( ((LL)factorial[i - 1] * (LL)i) % MOD);
	}
	return;
}

int find_seq_rank() {
	LL ret = 0;

	for (int i = 0; i < k; i++) {
		int val = sum(seqtree, seq[i]);
		mulval[i] = (seq[i] - val - 1);
		ret = (ret + (LL)(seq[i] - val-1) * (LL)factorial[k - i - 1])%MOD;
		update(seqtree, seq[i], 1);
	}

	return (int)((ret +1)%MOD);
}

int main() {
	make_factorial();
	si(k); si(n);
	seqtree = vector< int>(k+1);
	for (int i = 0; i < k; i++){
		si(seq[i]);
	}

	seq_rank = find_seq_rank();

	for (int i = 0,a,b; i < n; i++) {
		si(a); si(b); 
		a--; b--;
		A[i] = a;
		B[i] = b;
		query[a].push_back(MP(b,i));
		query[b].push_back(MP(a,i));

	}

	midsumtree = vector <int>(k + 1);
	seqtree = vector <int>(k + 1);

	for (int i = 0; i < k; i++) {

		for (int j = 0, cur, index, val; j < query[i].size(); j++) {
			cur = query[i][j].first;
			index = query[i][j].second;

		// 양끝 부분			
			val = (seq[cur] - sum(seqtree, seq[cur]) - 1) - mulval[i];
			val = ( (LL)val*(LL)factorial[k - i -1])%MOD;
			ans[index] = (ans[index] + val + MOD) % MOD;

		//중간 부분
			val = sum(midsumtree, seq[cur]);
			midsum[i][j] = val;
		} 
		//트리 갱신
		update(seqtree, seq[i], 1);
		update(midsumtree, seq[i], factorial[k - i - 1]);

	}

	for (int i = 0, a, b, val; i < n; i++) {
		a = A[i];
		b = B[i];

		val = seq_rank;
		val += ans[i];
		//val += midsum;
		printf("%d\n", val);


	}

	printf("%d\n", ans);
	return 0;
}