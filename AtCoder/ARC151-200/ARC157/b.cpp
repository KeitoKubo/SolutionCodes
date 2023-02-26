#define _USE_MATH_DEFINES
#include <iostream>                         // cout, endl, cin
#include <cstdio>                           // printf, scanf
#include <string>                           // string, to_string, stoi
#include <algorithm>                        // min, max, swap, lower_bound, upper_bound, stable_sort, sort, reverse
#include <cmath>                            //sin(rad),cos,tan, abs, pow, sqrt, cbrt,  exp, log, log10, log2
#include <utility>                          // pair, make_pair
#include <map>                              // map
#include <set>                              // set
#include <vector>                           // vector
#include <queue>                            // queue, priority_queue
#include <stack>                            // stack
#include <list>                             // list
#include <deque>                            // deque
#include <iomanip>
#include <numeric>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<string, bool> msb;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;

#define infi 2147483647
#define infl 9223372036854775806
#define MOD  1000000007
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repa(i,n) for(int i=1;i<=(int)n;i++)
#define irep(i,n) for(int i=(int)n-1;i>=0;i--)

//Union Find Tree
class DisjointSet {
public:
	vi rank, p, child; //rankはその木の深さ、pは親ノード

	DisjointSet() {}
	DisjointSet(int size) {
		rank.resize(size + 1, 0);
		p.resize(size + 1, 0);
		child.resize(size + 1, 0);
		repa(i, size) makeSet(i);
	}

	void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
		child[x] = 1;
	}

	int findSet(int x) {
		if (x != p[x]) p[x] = findSet(p[x]);
		return p[x];
	}

	int howmanychilds(int x) {
		return child[x];
	}

	bool same(int x, int y) {
		if (findSet(x) == findSet(y)) return true;
		else return false;
	}

	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
			child[x] += child[y];
		}
		else {
			p[x] = y; child[y] += child[x];
			if (rank[x] == rank[y]) rank[y]++;
		}
	}

	void unite(int x, int y) {
		link(findSet(x), findSet(y));
	}
};

//sort vector<pii> by second element
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

//---------------------------------------------------


int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n, k; string s; cin >> n >> k >> s;

	int x_count = 0;
	rep(i, n) { if (s[i] == 'X') x_count++; }
	//全部X or 全部Y
	if (x_count == 0) { std::cout << max(0, n - 1 - k) << endl; return 0; }
	if (x_count == n) { std::cout << max(0, k - 1) << endl; return 0; }

	priority_queue<int> PQX, PQY;
	//連続部分にわける
	s += "Z";
	int x_side = 0, y_side = 0;
	int pos = 0; //連続部の最初の位置
	char c = s[0]; //連続部の文字
	int ans = 0; //隣り合うYの数
	for (int i = 1; i <= n; i++) {
		if (c == 'Y' && s[i] != 'Y') {
			if (pos == 0 || i==n) { //端のY
				y_side += i - pos;
			}
			else {
				PQY.push(i - pos);
			}
			ans += (i - pos - 1); pos = i; c = s[i];
		}
		if (c == 'X' && s[i] != 'X') {
			if (pos == 0 || i == n) {
				x_side += i - pos;
			}
			else {
				PQX.push((i - pos) * -1); 
			}
			pos = i; c = s[i];
		}
	}

	//kがxの個数よりも多い場合
	if (k >= x_count) {
		int p = k - x_count; //全てYになった状態から、残りswap回数
		ans = n - 1;
		if (y_side >= p) { std::cout << ans - p << endl; return 0; }

		p -= y_side; ans -= y_side;
		while (!PQY.empty() && p > 0) {
			int x = PQY.top(); PQY.pop();
			int next = min(x, p);
			ans -= (next + 1); p -= next;
		}
		std::cout << max(0, ans) << endl; return 0;
	}

	//kはxの個数よりも少ない
	int p = k;
	while (!PQX.empty()) {
		int x = PQX.top(); PQX.pop();
		x *= -1;
		if (p < x) { cout << ans + p << endl; return 0; }
		ans += x + 1; p -= x;
	}
	//端のxのみ残っている
	ans += p;
	std::cout << ans << endl;
	return 0;
}

