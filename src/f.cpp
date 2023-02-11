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

	vi vec_x, vec_y;
	if ((b - a) % 2 == 1 || (d - c % 2 == 1)) {
		cout << "No" << endl;
	}
	else if (tx + sx <= 1000000 * b - 499999 * 2 * a && ty + sy <= 500000 * 2 * d - 499999 * 2 * c) { //奇数回操作
		int zeroflag_x = 0;
		if (b == a) {
			if (sx != tx) { cout << "No" << endl; return 0; }
			else zeroflag_x = 1;
		}
		else {
			ll btoa_x = (tx + sx) / (2 * (b - a)), mod_x = (tx + sx) % (2 * (b - a));
			mod_x /= 2;
			if (mod_x < a) {
				while (mod_x < a) {
					if (btoa_x <= 0) { cout << "No" << endl; return 0; }
					mod_x += b - a; btoa_x--;
				}
			}
		}

		int zeroflag_y = 0;
		if (c == d) {
			if (sy != ty) { cout << "No" << endl; return 0; }
			else zeroflag_y = 1;
		}
		else {
			ll btoa_y = (ty + sy) / (2 * (b - a)), mod_y = (ty + sy) % (2 * (b - a));
			mod_y /= 2;
			if (mod_y < c) {
				while (mod_y < c) {
					if (btoa_y <= 0) { cout << "No" << endl; return 0; }
					mod_y += d - c; btoa_y--;
				}
			}
		}
	}
	else if (tx - sx <= 1000000 * (b - a) && ty - sy <= 1000000 * (d - c)) { //偶数回操作

	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

