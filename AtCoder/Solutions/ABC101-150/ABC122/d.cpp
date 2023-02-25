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
const int max_n = 101;
ll dp[max_n][65];
int n;


int main() {
	//int a = in<int>(); string b = in<string>(); char c = in<char>();
	//double d = in<double>();
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	std::cin >> n;

	repa(i, n) {
		rep(j, 64) dp[i][j] = 0;
	}
	rep(i, 64) dp[3][i] = 1;

	for (int i = 4; i <= n; i++) {
		rep(j, 64) {
			int x = j % 16; //下2けた
			int y = x * 4;
			if (j == 6 || j == 9 || j == 33) continue;
			else if (j == 8) {
				rep(k, 4) {
					if (k != 1) { dp[i][y + k] += dp[i - 1][j]; dp[i][y + k] %= MOD; }
				}
			}
			else if (j ==10 || j == 11) {
				rep(k, 4) {
					if (k != 1) { dp[i][y + k] += dp[i - 1][j]; dp[i][y + k] %= MOD; }
				}
			}
			else if (j==2 || j==6 || j==10 || j==14) {
				rep(k, 4) {
					if (k != 1) { dp[i][y + k] += dp[i - 1][j]; dp[i][y + k] %= MOD; }
				}
			}
			else if (x == 2) {
				rep(k, 4) {
					if (k != 1) { dp[i][y + k] += dp[i - 1][j]; dp[i][y + k] %= MOD; }
				}
			}
			else if (x == 1) {
				rep(k, 4) {
					if (k != 2) { dp[i][y + k] += dp[i - 1][j]; dp[i][y + k] %= MOD; }
				}
			}
			else if (x == 8) {
				rep(k, 4) {
					if (k != 1) { dp[i][y + k] += dp[i - 1][j]; dp[i][y + k] %= MOD; }
				}
			}
			else {
				rep(k, 4) {
					dp[i][y + k] += dp[i - 1][j]; dp[i][y + k] %= MOD;
				}
			}
		}
	}

	ll ans = 0;
	rep(i, 64) {
		if (i != 6 && i != 9 && i != 33)ans += dp[n][i];
	}

	cout << ans % MOD << endl;

	return 0;
}
