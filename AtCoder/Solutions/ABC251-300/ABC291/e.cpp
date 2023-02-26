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
const int MX = 2e5 + 2;
vector<int> e[MX];
map<pii, bool> mp;
map<pii, bool> mp2;
int digin[MX];
int used[MX];
int node[MX];
int a[MX];
int n, m;

int last = -1;
int dfs(int s, int p) {
	used[s] = true;
	int depth = p;
	if (depth == n - 1) {
		last = n - 1; node[n - 1] = s; return n - 1;
	}
	for (int u : e[s]) {
		pii P = make_pair(s, u);
		if (!used[u] && !mp2[P]) {
			int next = dfs(u, p + 1);
			//dfsの値がn-1よりも小さいのなら、もう探索する必要がない
			if (next < n - 1) {
				mp2[P] = true; continue;
			}
			if (next >= depth) {
				depth = next;
				if (depth == n-1) {
					if (mp[P]) { last--; node[last] = s; }
				}
			}
		}
	}
    return depth;
}

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	cin >> n >> m;
	rep(i, m) {
		int x, y; (void)scanf("%d%d", &x, &y);
		--x; --y;
		if (!mp[make_pair(x, y)]) {
			e[x].push_back(y); digin[y]++; mp[make_pair(x, y)] = true;
		}
	}

	int p = 0;
	int s = -1;
	rep(i, n) {
		if (digin[i] == 0) { p++; s = i; }
	}


	if (p > 1) { cout << "No" << endl; return 0; }
	int max_depth = dfs(s, 0);
	if (max_depth != n - 1) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		rep(i, n) {
			a[node[i]] = i + 1;
		}
		rep(i, n) {
			if (i == n - 1) cout << a[i] << endl;
			else cout << a[i] << " ";
		}
	}

	return 0;
}

