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
vi e[MX];
int a[MX];
bool vst[MX];
int deg_in[MX];
int n, m;
vi ts_node;
map<pii, bool> mp;

void bfs(int s) {
	qi Q; Q.push(s);
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		vst[x] = true; ts_node.push_back(x);
		for (int y : e[x]) {
			deg_in[y]--;
			if (deg_in[y] == 0 && !vst[y]) {
				Q.push(y);
			}
		}
	}
}

void ts() {
	rep(i, n) vst[i] = false;
	rep(i, n) {
		if (!vst[i] && deg_in[i] == 0) bfs(i);
	}
}

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	cin >> n >> m;
	rep(i, m) {
		int x, y; (void)scanf("%d%d", &x, &y);
		--x; --y;
		e[x].push_back(y); deg_in[y]++;
		mp[make_pair(x, y)] = true;
	}
	ts();

	bool flag = false;
	rep(i, ts_node.size() - 1) {
		int s = ts_node[i], t = ts_node[i + 1];
		if (!mp[make_pair(s, t)]) flag = true;
	}

	if (flag) cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		rep(i, ts_node.size()) {
			a[ts_node[i]] = i + 1;
		}
		rep(i, n) {
			if (i == n - 1) cout << a[i] << endl;
			else cout << a[i] << " ";
		}
	}


	return 0;
}

