#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

typedef unsigned usi;
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
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef complex<double> cmp;

#define infi 2147483647
#define infl 9223372036854775806
#define MOD  1000000007
#define EPS 0.0000000001
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define repa(i,n) for(int i = 1; i <= (int)n; i++)
#define irep(i,n) for(int i = (int)n - 1;i >= 0; i--)
#define irepa(i,n) for(int i = (int)n; i >= 1; i--)

//---------------------------------------------------
const unsigned MX = 2e5 + 2;
const int INF = 300000;
bool used[MX][2]; //頂点と反転したかの組を状態としてdfs
vector<pii> e[MX];
int dist[MX][2];
int s[MX];
int n, m, k;

void bfs() {
	dist[0][0] = 0;
	queue<pii> Q; Q.emplace(0, 0); used[0][0] = true;
	while (!Q.empty()) {
		auto [x, p] = Q.front(); (void)Q.pop();
		for (auto [y, q] : e[x]) {
			if ((p + q) % 2 == 1 && !used[y][p]) { //反転しない
				dist[y][p] = min(dist[y][p], dist[x][p] + 1);
				used[y][p] = true; Q.emplace(y, p);
			}
			else if (s[x] == 1 && (p + q) % 2 == 0 && !used[y][(p + 1) % 2]) {//反転する
				dist[y][(p + 1) % 2] = min(dist[y][(p + 1) % 2], dist[x][p] + 1);
				used[y][(p + 1) % 2] = true; Q.emplace(y, (p + 1) % 2);
			}
		}
	}
}

int main() {
	cin >> n >> m >> k;
	rep(i, n)rep(j, 2) dist[i][j] = INF;
	rep(i, n)rep(j, 2) used[i][j] = false;
	rep(i, n) s[i] = 0;
	rep(i, m) {
		int x, y, z; (void)scanf("%d%d%d", &x, &y, &z);
		--x; --y;
		e[x].emplace_back(y,z); e[y].emplace_back(x,z);
	}
	rep(i, k) {
		int z; (void)scanf("%d", &z); 
		--z; s[z] = 1;
	}
	bfs();
	int ans = min(dist[n - 1][0], dist[n - 1][1]);
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}

