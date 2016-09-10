//문자열 매칭 아호코라식 기본구현
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

#define LL long long
#define pii pair < int,int>
#define si(a) scanf("%d",&(a))
#define ss(a) scanf("%s",(a))
#define sLL(a) scanf("%lld",&(a))
#define INF 1234567890
#define LLINF 12345678912345678
#define all(a) (a).begin(),(a).end()
//////////////////////////////////////////////////////////////////////////////////////////

int T,ans;
int n, q;

const int alphabet = 26;
int tonum(char c) { return c - 'a'; }
struct Node {
	Node* children[alphabet];

	//현재 위치에서 끝나는 문자열 번호
	int terminal;
	//실패연결
	Node* fail;
	//이노드에 방문했을댸 등장하는 바늘들의 번호
	vector<int>output;

	Node() :terminal(-1) {
		memset(children, 0, sizeof(children));
	}
	~Node() {
		for (int i = 0; i < alphabet; i++) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char* key,int id) {
		if (*key == 0)terminal = id;
		else {
			int next = tonum(*key);
			if (children[next] == NULL)
				children[next] = new Node();
			children[next]->insert(key + 1,id);
		}
	}

	//TrieNode* find(const char* key) {
	//	if (*key == 0) return this;
	//	int next = tonum(*key);
	//	if (children[next] == NULL)return NULL;
	//	return children[next]->find(key + 1);
	//}
};

void computeFailfunc(Node* root) {
	queue<Node*> q;
	root->fail = root;
	q.push(root);
	while (!q.empty()) {
		Node* cur = q.front();
		q.pop();

		for (int edge = 0; edge < alphabet; edge++) {
			Node* child = cur->children[edge];
			if (!child)continue;

			if (cur == root)
				child->fail = root;
			else {
				Node* failnode = cur->fail;
				while (failnode != root && failnode->children[edge] == NULL)
					failnode = failnode->fail;
				if (failnode->children[edge])
					failnode = failnode->children[edge];
				child->fail = failnode;
			}

			child->output = child->fail->output;
			if (child->terminal >=1)
				child->output.push_back(child->terminal);
			q.push(child);
		}
	}
}

int ahoCorasick(const string& s, Node* root) {
	/*vector<pii> ret;*/
	int count = 0;
	Node* cur = root;
	for (int i = 0; i < s.size(); i++) {
		int chr = tonum(s[i]);
		while (cur != root && cur->children[chr] == NULL) {
			cur = cur->fail;

		}
		if (cur->children[chr])
			cur = cur->children[chr];

		if (cur->output.size())
			return 1;

	}
	return 0;
}

char pattern[100000];


int main(){	
	Node root;
	si(n);
	for (int i = 0; i < n; i++) {
		memset(pattern, 0, sizeof(pattern));
		ss(pattern);
		root.insert(pattern,i+1);
	}

	//실패함수생성
	computeFailfunc(&root);

	si(q);
	char temp[100010];
	for (int i = 0; i < q; i++) {
		ss(temp);
		string str(temp);

		int ans = ahoCorasick(str, &root);	
		if (ans == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}

	
	return  0;
}