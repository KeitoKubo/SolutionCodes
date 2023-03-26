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
char g[21][21];
char h[21][21];

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int r, c; cin >> r >> c;
	rep(i, r) rep(j, c) cin >> g[i][j];
	rep(i, r) rep(j, c) h[i][j] = g[i][j];

	rep(i, r) rep(j, c) {
		if (g[i][j] != '.' && g[i][j] != '#') {
			int x = g[i][j] - '0';
			for (int p = 0; p <= x; ++p) {
				for (int q = 0; p + q <= x; ++q) { //たてにp、よこにq
					if (i - p >= 0 && j - q >= 0) h[i-p][j-q] = '.';
					if (i - p >= 0 && j + q < c) h[i - p][j + q] = '.';
					if (i + p  < r && j + q < c) h[i + p][j + q] = '.';
					if (i + p  < r && j - q >= 0) h[i + p][j - q] = '.';
				}
			}
		}
	}

	rep(i, r) {
		rep(j, c) {
			cout << h[i][j];
		}
		cout << endl;
	}

	return 0;
}

