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
	ll L; int n1, n2;
	cin >> L >> n1 >> n2;

	vector<pair<int,ll>> v1(n1), v2(n2);
	rep(i, n1) {
		(void)scanf("%d%lld", &v1[i].first, &v1[i].second);
	}
	rep(i, n2) {
		(void)scanf("%d%lld", &v2[i].first, &v2[i].second);
	}

	ll as, bs, at, bt, cura, curb;
	as = bs = -1; at = v1[0].second - 1; bt = v2[0].second - 1;//今見ている始点と終点
	cura = curb = 0; //注目している要素は何番目か

	ll ans = 0;

	while (true) {
		int x = v1[cura].first, y = v2[curb].first;
		if (x == y) {
			ans += min(at, bt) - max(as, bs);
		}
		if (at >= bt) { //bを1つ進める
			++curb; if (curb == n2) break;
			bs = bt; bt = bs + v2[curb].second;
		}
		else { //aを1つ進める
			++cura; if (cura == n1) break;
			as = at; at = as + v1[cura].second;
		}
	}

	cout << ans << endl;

	return 0;
}

