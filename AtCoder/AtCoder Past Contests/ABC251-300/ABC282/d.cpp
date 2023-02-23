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
const int maxi = 2e5 + 2;
vi e[maxi];
bool checked[maxi];
int color[maxi]; //色は1か2で塗る
int n, m;

void solve() { //二部グラフなら行う処理
	ll sum_1 = 0, sum_2 = 0; //連結部の頂点数の二乗の総和、連結成分内で完全2部グラフになるまでに不足している辺の数の総和
	repa(i, n) {
		if (!checked[i]) {
			int _vertex = 0;
			int _edges = 0; //辺の数、最後に2で割ることを忘れずに
			int _color_one_count = 0;
			qi Q; Q.push(i); color[i] = 1;
			while (!Q.empty()) {
				int x = Q.front(); Q.pop();
				if (!checked[x]) {
					checked[x] = true;
					if (color[x] == 1) _color_one_count++;
					_vertex++;
					int next_color = 3 - color[x];
					_edges += e[x].size();
					rep(j, e[x].size()) {
						if (!checked[e[x][j]]) {
							int next_node = e[x][j];
							color[next_node] = next_color;
							Q.push(next_node);
						}
					}
				}
			}
			_edges /= 2;

			//計算処理
			sum_1 += (ll)_vertex * (ll)_vertex;
			sum_2 += (ll)_color_one_count * (ll)(_vertex - _color_one_count) - (ll)_edges;
		}
	}
	cout << ((ll)n * (ll)n - sum_1) / 2 + sum_2 << endl;
}

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	cin >> n >> m;
	DisjointSet ds(n * 2);
	rep(i, m) {
		int x, y; (void)scanf("%d%d", &x, &y);
		e[x].push_back(y); e[y].push_back(x);
		--x; --y;
		ds.unite(x, y + n);
		ds.unite(y, x + n);
	}

	bool flag = false;
	rep(i, n) {
		if (ds.same(i, i + n)) flag = true;
	}

	if (flag) cout << 0 << endl;
	else solve();

	return 0;
}

