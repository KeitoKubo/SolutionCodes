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
const int MX = 1e5 + 2;
int fdp[MX], bdp[MX];
vector<string> s;
int n, m;


int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );

	//1-indexed
	cin >> n >> m;
	rep(i, n) {
		string str; cin >> str; s.push_back(str);
	}
	repa(i, n) { fdp[i] = bdp[i] = infi; }
	fdp[1] = 0; bdp[n] = 0;

	//fdp
	repa(i, n) {
		if (fdp[i] != infi) {
			string str = s[i - 1];
			rep(j, str.length()) {
				if (str[j] == '1' && i+j+1 <= n) {
					fdp[i + j + 1] = min(fdp[i + j + 1], fdp[i] + 1);
				}
			}
		}
	}

	//bdp
	for (int i = n; i >= 1; i--) {
		if (bdp[i] != infi) {
			for (int nxt = i - 1; nxt >= max(1, i - m); nxt--) {
				string str = s[nxt - 1];
				if (str[i - nxt - 1] == '1') {
					bdp[nxt] = min(bdp[nxt], bdp[i] + 1);
				}
			}
		}
	}

	vi v;
	for (int k = 2; k < n; k++) {
		int ans = infi;
		for (int i = max(1, k - m + 1); i < k; i++) {
			if (fdp[i] != infi) {
				string str = s[i - 1];
				for (int j = k + 1; j <= min(n, k + m - 1); j++) {
					if (j - i <= m && bdp[j] != infi) {
						if (str[j - i - 1] == '1') {
							ans = min(ans, fdp[i] + bdp[j] + 1);
						}
					}
				}
			}
		}
		if (ans == infi) v.push_back(-1);
		else v.push_back(ans);
	}

	rep(i, v.size()) {
		if (i == v.size() - 1) cout << v[i] << endl;
		else cout << v[i] << " ";
	}

	return 0;
}

