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

const int MXint = 2e5;

using Mint = atcoder::modint998244353;
vector<Mint> fact(MXint);
struct modinv {
	int n; vector<Mint> d;
	modinv() : n(2), d({ 0,1 }) {}
	Mint operator()(int i) {
		while (n <= i) d.push_back(-d[Mint::mod() % n] * (Mint::mod() / n)), ++n;
		return d[i];
	}
	Mint operator[](int i) const { return d[i]; }
} invs;
struct modfact {
	int n; vector<Mint> d;
	modfact() : n(2), d({ 1,1 }) {}
	Mint operator()(int i) {
		while (n <= i) d.push_back(d.back() * n), ++n;
		return d[i];
	}
	Mint operator[](int i) const { return d[i]; }
} facts;
struct modfactinv {
	int n; vector<Mint> d;
	modfactinv() : n(2), d({ 1,1 }) {}
	Mint operator()(int i) {
		while (n <= i) d.push_back(d.back() * invs(n)), ++n;
		return d[i];
	}
	Mint operator[](int i) const { return d[i]; }
} ifacts;
Mint comb(int n, int k) {
	if (n < k || k < 0) return 0;
	return facts(n) * ifacts(k) * ifacts(n - k);
}

//---------------------------------------------------

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	
	ll n, m; cin >> n >> m;
	ll ans = -1;
	for (ll a = 1; a <= n; a++) {
		ll b = (m + a - 1) / a;
		if (b <= n) {
			if (ans == -1) ans = a * b;
			ans = min(ans, a * b);
		}
		if (a * a >= m) break;
	}
	cout << ans << endl;

	return 0;
}

