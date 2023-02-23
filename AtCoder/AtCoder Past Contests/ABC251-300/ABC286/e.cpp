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
const int maxi = 302;
vi e[maxi];
ll a[maxi];
int n;
ll ans[maxi][maxi];
int _depth_ans[maxi][maxi];

void solve(int s) {

	ll _value[maxi];
	repa(i, n) _value[i] = -1;
	bool fixed[maxi]; //値が既に決まったか
	memset(fixed, 0, sizeof(fixed));
	int _depth[maxi]; 
	repa(i, n) _depth[i] = 1000;
	qi Q; Q.push(s); _value[s] = a[s]; _depth[s] = 0;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		if (!fixed[x]) {
			fixed[x] = true;
			rep(j, e[x].size()) {
				if (!fixed[e[x][j]] && _depth[e[x][j]] > _depth[x]) {
					int next = e[x][j]; _depth[next] = _depth[x] + 1;
					_value[next] = max(_value[next], _value[x] + a[next]);
					Q.push(next);
				}
			}
		}
	}
	repa(i, n) {
		if (_value[i] == -1) ans[s][i] = -1;
		else {
			ans[s][i] = _value[i]; _depth_ans[s][i] = _depth[i];
		}
	}

}

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	cin >> n;
	repa(i, n)(void)scanf("%lld", &a[i]);
	repa(i, n) {
		string s; cin >> s;
		rep(j, s.length()) {
			if (s[j] == 'Y') e[i].push_back(j + 1);
		}
	}
	repa(i, n) {
		solve(i);
	}

	int q; cin >> q;
	rep(i, q) {
		int u, v; (void)scanf("%d%d", &u, &v);
		if (u == v || ans[u][v] == -1) {
			cout << "Impossible" << endl;
		}
		else cout << _depth_ans[u][v] << " " << ans[u][v] << endl;
	}


	//連結か判定する部分
	/*
	bool checked[maxi];
	int _color = 0;
	repa(i, n) {
		if (!checked[i]) {
			qi Q; Q.push(i);
			while (!Q.empty()) {
				int x = Q.front(); Q.pop();
				if (!checked[x]) {
					checked[x] = true; color[x] = _color;
					rep(j, e[x].size()) {
						if (!checked[e[x][j]]) {
							Q.push(e[x][j]);
						}
					}
				}
			}
			_color++;
		}
	}
	*/


	return 0;
}

