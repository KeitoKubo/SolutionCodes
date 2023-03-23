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
const unsigned MX = 201;
int n;
ll d[MX][MX];
ll x[MX], y[MX];
ll p[MX];


int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	cin >> n;
	rep(i, n) {
		(void)scanf("%lld%lld%lld", &x[i], &y[i], &p[i]);
	}
	rep(i, n) {
		rep(j, n) {
			ll dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			if (dist % p[i] == 0) { d[i][j] = dist / p[i]; }
			else d[i][j] = dist / p[i] + 1;
		}
	}

	//iからjへ移動するパスの中で、辺の最大値が最小になるものを見つける
	rep(k, n) {
		rep(i, n) {
			rep(j, n) {
				d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
			}
		}
	}

	ll ans = infl;
	rep(i, n) {
		ll cur = 0;
		rep(j, n) {
			cur = max(cur, d[i][j]);
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;

	return 0;
}

