//
//#include <stdio.h>
//#include <vector>
//#include <set>
//#include <algorithm>
//#include <queue>
//#include <math.h>
//#include <iostream>
//#include <stack>
//#include <string>
//#include <string.h>
//using namespace std;
//
//#define LL long long
//#define pii pair < int,int>
//#define si(a) scanf("%d",&(a))
//#define ss(a) scanf("%s",(a))
//#define sLL(a) scanf("%lld",&(a))
//#define INF 1234567890
//#define LLINF 12345678912345678
//#define all(a) (a).begin(),(a).end()
////////////////////////////////////////////////////////////////////////////////////////////
//
//int T, ans;
//#define MAX_N 1000001
//#define MAX_M 101
//char str[MAX_N];
//char mark[MAX_M];
//int n, m;
//
//const int alphabet = 26;
//int tonum(char c) { return c - 'A'; }
//struct TrieNode {
//	TrieNode* children[alphabet];
//
//	//현재 위치에서 끝나는 문자열 번호
//	int terminal;
//	//실패연결
//	TrieNode* fail;
//	//이노드에 방문했을댸 등장하는 바늘들의 먼호
//	vector<int>output;
//
//	TrieNode() :terminal(false) {
//		memset(children, 0, sizeof(children));
//	}
//	~TrieNode() {
//		for (int i = 0; i < alphabet; i++) {
//			if (children[i])
//				delete children[i];
//		}
//	}
//
//	void insert(const char* key) {
//		if (*key == 0)terminal = true;
//		else {
//			int next = tonum(*key);
//			if (children[next] == NULL)
//				children[next] = new TrieNode();
//			children[next]->insert(key + 1);
//		}
//	}
//
//	TrieNode* find(const char*key) {
//		if (*key == 0) return this;
//		int next = tonum(*key);
//		if (children[next] == NULL)return NULL;
//		return children[next]->find(key + 1);
//	}
//
//};
//
//void computeFailfunc(TrieNode* root) {
//	queue<TrieNode*> q;
//	root->fail = root;
//	q.push(root);
//	while (!q.empty()) {
//		TrieNode* here = q.front();
//		q.pop();
//
//		for (int edge = 0; edge < alphabet; edge++) {
//			TrieNode* child = here->children[edge];
//			if (!child)continue;
//
//			if (here == root)
//				child->fail = root;
//			else {
//				TrieNode* t = here->fail;
//				while (t != root && t->children[edge] == NULL)
//					t = t->fail;
//				if (t->children[edge])
//					t = t->children[edge];
//				child->fail = t;
//			}
//
//			child->output = child->fail->output;
//			if (child->terminal != -1)
//				child->output.push_back(child->terminal);
//			q.push(child);
//		}
//	}
//}
//
//vector<pii> ahoCorasick(const string& s, TrieNode* root) {
//	vector<pii> ret;
//	TrieNode* state = root;
//	for (int i = 0; i < s.size(); i++) {
//		int chr = tonum(s[i]);
//		while (state != root & state->children[chr] == NULL)
//			state = state->fail;
//		if (state->children[chr])
//			state = state->children[chr];
//		for (int j = 0; j < state->output.size(); j++)
//			ret.push_back(pii(i, state->output[j]));
//	}
//	return ret;
//}
//
//int main() {
//	for (si(T); T>0; T--) {
//		si(n); si(m);
//		ss(str);
//		ss(mark);
//		TrieNode root;
//		char temp[1234];
//
//		//trie 구조 생성
//		for (int i = 0; i < m; i++) {
//			for (int j = i; j < m; j++) {
//				memset(temp, 0, sizeof(temp));
//				for (int index = 0; index < i; index++)
//					temp[index] = mark[index];
//
//				int r = 0;
//				for (int index = i; index <= j; index++) {
//					temp[index] = mark[j - r];
//					r++;
//				}
//
//				for (int index = j + 1; index < m; index++)
//					temp[index] = mark[index];
//				root.insert(temp);
//
//			}
//		}
//
//
//		//실패함수생성
//		computeFailfunc(&root);
//
//		vector <pii> list = ahoCorasick(str, &root);
//		int ans = 0;
//		for (int i = 0; i < list.size(); i++)
//			ans += list[i].second;
//
//		printf("%d\n", ans);
//	}
//}