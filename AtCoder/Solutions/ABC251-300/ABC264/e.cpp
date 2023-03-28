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

using Mint = atcoder::modint998244353;

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
const unsigned MX = 101;

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n, m, e; cin >> n >> m >> e;
	atcoder::dsu uf(n + 1); //発電所の番号は0
	vector<pii> edge(e);
	rep(i, e) {
		(void)scanf("%d %d", &edge[i].first, &edge[i].second);
	}
	int Q; cin >> Q; 
	vi que(Q);
	rep(i, Q) (void)scanf("%d", &que[i]);
	vi wir(e);
	rep(i, e) wir[i] = 1;
	rep(i, Q) wir[que[i] - 1] = 0;

	rep(i, e) {
		if (wir[i]) {
			int v1 = edge[i].first, v2 = edge[i].second;
			if (v1 > n) v1 = 0;
			if (v2 > n) v2 = 0;
			uf.merge(v1, v2);
		}
	}

	int ans = 0;
	repa(i, n) {
		if (uf.same(0, i)) ++ans;
	}

	vi con(Q + 1);
	con[Q] = ans;
	for (int i = Q - 1; i >= 0; --i) {
		int num = que[i] - 1;
		int v1 = edge[num].first, v2 = edge[num].second;
		if (v1 > n) v1 = 0;
		if (v2 > n) v2 = 0;
		bool flg1 = uf.same(0, v1), flg2 = uf.same(0, v2);
		if (!flg1 && flg2) {
			ans += uf.size(v1);
		}
		if (flg1 && !flg2) {
			ans += uf.size(v2);
		}
		uf.merge(v1, v2);
		con[i] = ans;
	}

	repa(i, Q) cout << con[i] << endl;

	return 0;
}

