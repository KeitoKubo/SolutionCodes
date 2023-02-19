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

#define MAX_V 50

struct edge { int to, cap, rev; };
vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int _from, int _to, int cap) {
	edge e = { _to, cap, G[_to].size() }; G[_from].push_back(e);
	e = { _from, 0, (int)G[_from].size() - 1 }; G[_to].push_back(e);
}

int dfs(int v, int t, int f) {//sからtへ移動可能ならそのルートの最大流量を返し、不可能なら0を返す。
	if (v == t) return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge& e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d; //逆辺の容量はdだけ増加する
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) { //O(F|E|) F:流量の最大値
	int flow = 0;
	while (true) { //パスがなくなるまでdfsを繰り返す
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, infi);
		if (f == 0) return flow;
		flow += f;
	}
}

const int max_n = 105;
const int max_K = 105;
int n, K;
bool can[max_n][max_K]; //コンピュータiが仕事jを行うことができる

void solve() {
	// 0 ～ n-1 : コンピュータに対応する頂点
	// n～n+K-1 : 仕事に対応する頂点

	int s = n + K, t = s + 1; //始点s,終点t

	rep(i, n) { //sからコンピュータへ容量1の辺をつなぐ
		add_edge(s, i, 1);  //from,to,cap
	}
	rep(i, K) { //仕事からtへ容量1の辺をつなぐ
		add_edge(i + n, t, 1);
	}

	//コンピュータと仕事をつなぐ
	rep(i, n) {
		rep(j, K) {
			if (can[i][j]) {
				add_edge(i, j + n, 1);
			}
		}
	}

	//Ford-Fulkersonで最大流
	int ans = max_flow(s, t);
	cout << ans << endl;
}

int main() {
	//入力
	cin >> n >> K;
	int q; cin >> q;
	rep(i, q) {
		int x, y; scanf("%d%d", &x, &y);
		can[x][y] = true;
	}
	solve();

	return 0;
}