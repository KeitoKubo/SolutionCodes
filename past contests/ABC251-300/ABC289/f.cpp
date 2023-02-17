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
const ll maxi = 990000;
vector<ll> vec_x, vec_y;

int main() {
	ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	ll a, b, c, d; cin >> a >> b >> c >> d;

	//偶数回移動
	int zeroflag_x = 0, zeroflag_y = 0;
	if ((sx + tx) % 2 == 1 || ((sy + ty) % 2 == 1)) {
		cout << "No" << endl; return 0;
	}
	//zeroflag
	if (b == a) {
		if (tx == sx) {
			zeroflag_x = 1;
			repl(i, maxi) vec_x.push_back(a);
		}
		else if ((tx + sx) == 2 * a) {
			zeroflag_x = 2;
			repl(i, maxi - 1) vec_x.push_back(a);
		}
		else {
			cout << "No" << endl; return 0;
		}
	}
	if (d == c) {
		if (ty == sy) {
			zeroflag_y = 1;
			repl(i, maxi) vec_y.push_back(d);
		}
		else if ((ty + sy) == 2 * d) {
			zeroflag_y = 2;
			repl(i, maxi - 1) vec_y.push_back(d);
		}
		else {
			cout << "No" << endl; return 0;
		}
	}

	if ((zeroflag_x == 0 || zeroflag_x == 1) && (zeroflag_y == 0 || zeroflag_y == 1)) {//偶数回操作
		if (zeroflag_x == 0) {
			if (tx >= sx) {
				ll move_x = (tx - sx) / (2 * (b - a));
				ll mod_x = (tx - sx) % (2 * (b - a)); mod_x /= 2;
				ll remain_x = maxi - 2 - 2 * move_x;
				repl(i, move_x) {
					vec_x.push_back(a); vec_x.push_back(b);
				}
				vec_x.push_back(b - mod_x);
				vec_x.push_back(b);
				repl(i, remain_x) {
					vec_x.push_back(b);
				}
			}
			else {
				ll move_x = (sx - tx) / (2 * (b - a));
				ll mod_x = (sx - tx) % (2 * (b - a)); mod_x /= 2;
				ll remain_x = maxi - 2 - 2 * move_x;
				repl(i, move_x) {
					vec_x.push_back(b); vec_x.push_back(a);
				}
				vec_x.push_back(b);
				vec_x.push_back(b - mod_x);
				repl(i, remain_x) {
					vec_x.push_back(b);
				}
			}
		}
		if (zeroflag_y == 0) {
			if (ty >= sy) {
				ll btoa_y = (ty - sy) / (2 * (d - c));
				ll mod_y = (ty - sy) % (2 * (d - c)); mod_y /= 2;
				ll remain = maxi - 2 - 2 * btoa_y;
				repl(i, btoa_y) {
					vec_y.push_back(c); vec_y.push_back(d);
				}
				vec_y.push_back(d - mod_y);
				vec_y.push_back(d);
				repl(i, remain) {
					vec_y.push_back(d);
				}
			}
			else {
				ll move_y = (sy - ty) / (2 * (d - c));
				ll mod_y = (sy - ty) % (2 * (d - c)); mod_y /= 2;
				ll remain = maxi - 2 - 2 * move_y;
				repl(i, move_y) {
					vec_y.push_back(d); vec_y.push_back(c);
				}
				vec_y.push_back(d);
				vec_y.push_back(d - mod_y);
				repl(i, remain) {
					vec_y.push_back(d);
				}
			}
		}
	}
	else if ((zeroflag_x == 0 || zeroflag_x == 2) && (zeroflag_y == 0 || zeroflag_y == 2)) {//奇数回操作
		if (zeroflag_x == 0) {
			ll move_x = (tx + sx) / (2 * (b - a));
			ll mod_x = (tx + sx) % (2 * (b - a)); mod_x /= 2;
			ll count_x = 0;
			while (mod_x < a) {
				mod_x += b - a; count_x += (ll)1;
			}
			ll remain = maxi - 1 - 1 - 2 * move_x - 2 * count_x;
			vec_x.push_back(mod_x);
			repl(i, move_x) {
				vec_x.push_back(a); vec_x.push_back(b);
			}
			repl(i, count_x) {
				vec_x.push_back(b); vec_x.push_back(a);
			}
			repl(i, remain) {
				vec_x.push_back(b);
			}
		}
		if (zeroflag_y == 0) {
			ll move_y = (ty + sy) / (2 * (d - c));
			ll mod_y = (ty + sy) % (2 * (d - c)); mod_y /= 2;
			ll count_y = 0;
			while (mod_y < c) {
				mod_y += d - c; count_y += (ll)1;
			}
			ll remain = maxi - 1 - 1 - 2 * move_y - 2 * count_y;
			vec_y.push_back(mod_y);
			repl(i, move_y) {
				vec_y.push_back(c); vec_y.push_back(d);
			}
			repl(i, count_y) {
				vec_y.push_back(d); vec_y.push_back(c);
			}
			repl(i, remain) {
				vec_y.push_back(d);
			}
		}
	}
	else {//不可能操作
		cout << "No" << endl; return 0;
	}

	cout << "Yes" << endl;
	rep(i, max(vec_x.size(), vec_y.size())) {
		cout << vec_x[i] << " " << vec_y[i] << endl;
	}

	return 0;
}

