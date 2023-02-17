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
#define repl(i,n) for(ll i=0;i<(ll)n;i++)

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
	ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
	ll a, b, c, d; cin >> a >> b >> c >> d;

	//必ず10^6回もしくは10^6-1回移動させることを考える
	vector<ll> vec_x, vec_y;
	int zeroflag_x = 0, zeroflag_y = 0;
	if ((sx + tx) % 2 == 1 || ((sy + ty) % 2 == 1)) {
		cout << "No" << endl; return 0;
	}
	/*else if (tx + sx <= 1000000 * b - 499999 * 2 * a && ty + sy <= 500000 * 2 * d - 499999 * 2 * c) { //奇数回操作
		//x部分
		if (b == a) {
			if (sx + tx != 2*b) { cout << "No" << endl; return 0; }
			else {
				rep(i, 1000000 - 1) vec_x.push_back(b);
			}
		}
		else {
			ll btoa_x = (tx + sx) / (2 * (b - a)); //b,aと2回の対象移動をする回数
			ll mod_x = (tx + sx) % (2 * (b - a));
			mod_x /= 2;
			if (mod_x < a) {
				while (mod_x < a) {
					if (btoa_x <= 0) { cout << "called 2x No" << endl; return 0; }
					mod_x += b - a; btoa_x--;
				}
			}
			ll remain = 1000000 - 1 - 1 - 2 * btoa_x; //残りの移動回数、必ず偶数になるのでa,aと対象移動をさせればよい
			vec_x.push_back(mod_x);
			rep(i, btoa_x) {
				vec_x.push_back(b); vec_x.push_back(a);
			}
			rep(i, remain) {
				vec_x.push_back(a);
			}
		}

		//y部分
		if (c == d) {
			if (sy+ty != 2*d) { cout << "called 1y No" << endl; return 0; }
			else {
				rep(i, 1000000 - 1) vec_y.push_back(d);
			}
		}
		else {
			ll btoa_y = (ty + sy) / (2 * (d - c)), mod_y = (ty + sy) % (2 * (d - c));
			mod_y /= 2;
			if (mod_y < c) {
				while (mod_y < c) {
					if (btoa_y <= 0) { cout << "called 2y No" << endl; return 0; }
					mod_y += d - c; btoa_y--;
				}
			}
			ll remain = 1000000 - 1 - 1 - 2 * btoa_y; //残りの移動回数、必ず偶数になるのでa,aと対象移動をさせればよい
			vec_y.push_back(mod_y);
			rep(i, btoa_y) {
				vec_y.push_back(d); vec_y.push_back(c);
			}
			rep(i, remain) {
				vec_y.push_back(c);
			}
		}

		cout << "Yes" << endl;
		rep(i, 1000000 - 1) {
			printf("%d %d\n", vec_x[i], vec_y[i]);
		}
	}*/

	//zeroflag
	if (b == a) {
		if (tx == sx) {
			zeroflag_x = 1;
			rep(i, 1000000) vec_x.push_back(b);
		}
		else if ((tx + sx) == 2 * b) {
			zeroflag_x = 2;
			rep(i, 1000000 - 1) vec_x.push_back(b);
		}
		else {
			cout << "No" << endl; return 0;
		}
	}
	if (d == c) {
		if (ty == sy) {
			zeroflag_y = 1;
			rep(i, 1000000) vec_y.push_back(d);
		}
		else if ((ty + sy) == 2 * d) {
			zeroflag_y = 2;
			rep(i, 1000000 - 1) vec_y.push_back(d);
		}
		else {
			cout << "No" << endl; return 0;
		}
	}

	if ((tx - sx) <= 1000000 * (b - a) && (ty-tx) <= 1000000*(d-c) && (zeroflag_x == 0 || zeroflag_x == 1) && (zeroflag_y==0 || zeroflag_y==1)) {//偶数回操作
		if (zeroflag_x == 0) {
			ll btoa_x = (tx - sx) / (2 * (b - a));
			ll mod_x = (tx - sx) % (2 * (b - a)); mod_x /= 2;
			ll remain_x = 1000000 - 2 - 2 * btoa_x;
			repl(i, btoa_x) {
				vec_x.push_back(a); vec_x.push_back(b);
			}
			vec_x.push_back(b - mod_x);
			vec_x.push_back(b);
			repl(i, remain_x) {
				vec_x.push_back(b);
			}
		}
		if (zeroflag_y == 0) {
			ll btoa_y = (ty - sy) / (2 * (d - c));
			ll mod_y = (ty - sy) % (2 * (d - c)); mod_y /= 2;
			ll remain = 1000000 - 2 - 2 * btoa_y;
			repl(i, btoa_y) {
				vec_y.push_back(c); vec_y.push_back(d);
			}
			vec_y.push_back(d - mod_y);
			vec_y.push_back(d);
			repl(i, remain) {
				vec_y.push_back(d);
			}
		}
	}
	else if ((tx + sx) <= 1000000 * b - 499999 * 2 * a && (ty + sy) <= 1000000 * d - 499999 * 2 * c && (zeroflag_x == 0 || zeroflag_x == 2) && (zeroflag_y==0 || zeroflag_y==2)) {//奇数回操作
		if (zeroflag_x == 0) {
			ll btoa_x = (tx + sx) / (2 * (b - a));
			ll mod_x = (tx + sx) % (2 * (b - a)); mod_x /= 2;
			ll count_x = 0;
			while (mod_x < a) {
				mod_x += b - a; count_x++;
			}
			if (btoa_x >= count_x) {
				count_x = 0; btoa_x -= count_x;
			}
			ll remain = 1000000 - 1 - 1 - 2 * btoa_x - 2 * count_x;
			repl(i, btoa_x) {
				vec_x.push_back(b); vec_x.push_back(a);
			}
			repl(i, count_x) {
				vec_x.push_back(a); vec_x.push_back(b);
			}
			vec_x.push_back(mod_x);
			repl(i, remain) {
				vec_x.push_back(b);
			}
		}
		if (zeroflag_y == 0) {
			ll btoa_y = (ty + sy) / (2 * (d - c));
			ll mod_y = (ty + sy) % (2 * (d - c)); mod_y /= 2;
			ll count_y = 0;
			while (mod_y < c) {
				mod_y += d - c; count_y++;
			}
			if (btoa_y >= count_y) {
				count_y = 0; btoa_y -= count_y;
			}
			ll remain = 1000000 - 1 - 1 - 2 * btoa_y - 2 * count_y;
			repl(i, btoa_y) {
				vec_y.push_back(d); vec_y.push_back(c);
			}
			repl(i, count_y) {
				vec_y.push_back(c); vec_y.push_back(d);
			}
			vec_y.push_back(count_y);
			repl(i, remain) {
				vec_y.push_back(d);
			}
		}
	}
	else {//不可能操作
		cout << "No" << endl; return 0;
	}

	cout << "Yes" << endl;
	rep(i, vec_x.size()) {
		cout << vec_x[i] << " " << vec_y[i] << endl;
	}

	return 0;
}

