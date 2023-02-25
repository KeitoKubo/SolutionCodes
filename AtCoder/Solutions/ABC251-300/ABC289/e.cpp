#define _USE_MATH_DEFINES
#include <iostream>                         // cout, endl, cin
#include <cstdio>                           // printf, scanf
#include <string>                           // string, to_string, stoi
#include <algorithm>                        // min, max, swap, lower_bound, upper_bound
// & stable_sort, sort, reverse
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
#define repl(i,n) for(ll i=0;i<(ll)n;i+=(ll)1)

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
const int max_n = 1005;

void solve() {
	int n, m;
	vi edge[max_n];
	vi group_depth_1[max_n],group_depth_n[max_n]; //1を始点、nを始点をしたときの、深さごとのnodeの集合
	bool checked[max_n];
	int color[max_n];
	int status_0[max_n], status_n[max_n];
	int depth[max_n];
	int depth_1_to_n;

	cin >> n >> m;
	rep(i, n) {
		int x; scanf("%d", &x); color[i] = x;
	}
	rep(i, m) {
		int a, b; scanf("%d%d", &a, &b);
		--a; --b;
		edge[a].push_back(b); edge[b].push_back(a);
	}

	rep(i, n) { checked[i] = 0; depth[i] = 0; status_0[i] = 0; }
	qi Q; Q.push(0);
	while (!Q.empty()) {
		int _node = Q.front(); Q.pop();
		checked[_node] = 1;
		int _depth = depth[_node];
		rep(i, edge[_node].size()) {
			int next_node = edge[_node][i];
			if (!checked[next_node]) {
				status_0[next_node] = status_0[_node] + color[next_node];
				depth[next_node] = depth[_node] + 1;
				group_depth_1[depth[next_node]].push_back(next_node);
				Q.push(next_node);
			}
		}
	}

	if (!checked[n - 1]) { cout << -1 << endl; } //連結でない場合

	rep(i, n) { checked[i] = 0; depth[i] = 0; }
	qi Q; Q.push(n - 1);
	while (!Q.empty()) {
		int _node = Q.front(); Q.pop();
		checked[_node] = 1;
		int _depth = depth[_node];
		rep(i, edge[_node].size()) {
			int next_node = edge[_node][i];
			if (!checked[next_node]) {
				depth[next_node] = depth[_node] + 1;
				group_depth_n[depth[next_node]].push_back(next_node);
				Q.push(next_node);
			}
		}
	}

	depth_1_to_n = depth[0];
}

int main() {
	int T; cin >> T;
	rep(i, T) solve();


	return 0;
}

