//suffix array 접미사 배열
//LCP array (longest common prefix) 
//
//시간 복잡도 
//siffix array 느린 버전 O(n^2 * log(n))
//siffix array 빠른 버전(멘버-마이어스 알고리즘) O(nlog(n))
//LCP array  O(n)
//
//참고 자료
//https://en.wikipedia.org/wiki/Suffix_array
//http://blog.naver.com/PostView.nhn?blogId=infoefficien&logNo=220071111280&parentCategoryNo=&categoryNo=55&viewDate=&isShowPopularPosts=false&from=postView
//http://clearpal7.blogspot.kr/2016/06/blog-post_13.html
//http://egloos.zum.com/js7309/v/11113392
//http://idea-sketch.tistory.com/25
//http://blog.myungwoo.kr/57
//http://koosaga.myungwoo.kr/entry/Suffix-Array-%EC%A0%91%EB%AF%B8%EC%82%AC-%EB%B0%B0%EC%97%B4
//lcp 정당성
//http://m.blog.naver.com/dark__nebula/220419358547
//http://codeforces.com/blog/entry/12796
//
//
//
//문제 
//11656 접미사 배열 https://www.acmicpc.net/problem/11656
//5582 공통 부분 문자열 https://www.acmicpc.net/problem/5582
//https://www.acmicpc.net/problem/1605
//https://www.acmicpc.net/problem/11555
//https://www.acmicpc.net/problem/7966
//https://www.acmicpc.net/problem/1701
//https://www.acmicpc.net/problem/9248
//https://www.acmicpc.net/problem/11478
//https://www.acmicpc.net/problem/11479

#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX_N 1000

//siffix array 느린 버전 O(n^2 * log(n))
struct SA_CMP1 {
	const string& s;
	SA_CMP1(const string& s):s(s){}
	bool operator() (int a, int b) {
		return strcmp(s.c_str() + a, s.c_str() + b) < 0;
	}
};
vector<int> make_SA1(const string& s) {
	vector<int>perm;
	for (int i = 0; i < s.size(); i++) perm.push_back(i);

	sort(perm.begin(), perm.end(), SA_CMP1(s));
}

//siffix array 빠른 버전(멘버-마이어스 알고리즘) O(nlog(n))
struct SA_CMP2 {
	const vector<int>& group;
	int t;
	SA_CMP2(const vector<int>& _g, int _t) :group(_g), t(_t) {};
	bool operator()(int a, int b) {
		if (group[a] != group[b]) return group[a] < group[b];
		return group[a + t] < group[b + t];
	}
};
vector<int> make_SA2(const char *str) {
	int t = 1;
	int n = strlen(str);

	vector<int> group(n + 1);
	for (int i = 0; i < n; i++)
		group[i] = str[i];
	group[n] = -1;

	vector <int> perm(n);
	for (int i = 0; i < n; i++) 
		perm[i] = i;
	

	while (t < n) {
		SA_CMP2 cmp(group, t);
		sort(perm.begin(), perm.end(), cmp);

		t *= 2;
		if (t >= n)break;

		vector<int> newgroup(n + 1);
		newgroup[n] = -1;
		newgroup[perm[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(perm[i - 1], perm[i]))
				newgroup[perm[i]] = newgroup[perm[i - 1]] + 1;
			else
				newgroup[perm[i]] = newgroup[perm[i - 1]];
		}
		group = newgroup;
	}
	return perm;
}


//LCP array  O(n)
vector<int> make_lcp(const vector<int> &sa, const string &s) {
	int size = sa.size();
	vector<int> lcp(size, 0);
	vector<int> rev(size, 0);
	int k = 0, j;
	for (int i = 0; i < size; i++) rev[sa[i]] = i;
	for (int i = 0; i < size; i++) {
		if (rev[i] == 0) { k = 0; continue; }
		j = sa[rev[i] - 1];
		while (i + k < size && j + k < size && s[i + k] == s[j + k])k++;
		lcp[rev[i]] = k;
		k = max(k - 1, 0);
	}
	return lcp;
}


