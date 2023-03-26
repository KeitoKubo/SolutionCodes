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
const unsigned MX = 2005;
using Mint = atcoder::modint998244353;

vector<Mint> fact(MX);
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

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n, m, k; cin >> n >> m >> k;
	vi a(n);
	rep(i, n) (void)scanf("%d", &a[i]);
	sort(a.begin(), a.end(), greater<int>());
	int cnt = 0;
	while (a.size() && a.back() == 0) {
		(void)a.pop_back(); ++cnt;
	}

	fact[0] = Mint(1);
	repa(i, m) {
		fact[i] = fact[i - 1] * Mint(i);
	}

	vector<Mint> f(m + 1); //f[x] := x以下のものがK個未満であるような場合の数
	rep(x, m + 1) {
		f[x] = Mint(0);
		int sum = 0; //x以下が既にいくつあるか
		for (int na : a) if (na <= x) ++sum;
		rep(i, cnt + 1) {
			if (sum + i < k) { //x以下にするものの合計がk個未満である
				/*
				Mint now = fact[cnt];
				now /= fact[i];
				now /= fact[cnt - i];
				*/
				Mint now = comb(cnt, i);
				now *= Mint(x).pow(i);
				now *= Mint(m - x).pow(cnt - i);
				f[x] += now;
			}
		}
	}

	Mint all = Mint(m).pow(cnt); //全事象の場合の数
	Mint ans = Mint(0); 
	repa(x, m) {
		Mint now = f[x - 1] - f[x];
		now *= Mint(x);
		ans += now;
	}
	ans /= all;
	cout << ans.val() << endl;

	return 0;
}

