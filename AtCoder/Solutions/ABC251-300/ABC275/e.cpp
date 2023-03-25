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


int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	using Mint = atcoder::modint998244353;
	int n, m, k; cin >> n >> m >> k;
	vector<Mint> dp(n + 1);
	rep(i, n + 1) dp[i] = 0;
	dp[0] = 1;
	Mint ans = 0;
	repa(i, k) { //サイコロをi回ふった
		vector<Mint> dp2(n + 1);
		rep(j, n + 1) dp2[j] = 0;
		rep(x, n) { //0～n-1
			repa(p, m) {
				if (p <= n - x) dp2[x + p] += dp[x];
				else dp2[2 * n - p - x] += dp[x];
			}
		}
		Mint M = Mint(1);
		rep(j, k - i) M *= Mint(m);
		M *= dp2[n];
		ans += M;
		rep(j, n + 1) dp[j] = dp2[j];
	}

	Mint M = 1;
	rep(i, k) M *= m;
	ans /= M;
	cout << ans.val() << endl;

	return 0;
}

