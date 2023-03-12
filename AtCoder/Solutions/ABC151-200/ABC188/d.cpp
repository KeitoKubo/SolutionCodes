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


int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n; ll C; cin >> n >> C;
	vector<pair<int,pii>> v(2 * n); //second 1 -> a, 0  -> b;
	vector<ll> d(2 * n + 1);
	vector<ll> c(n); //daily cost of each service

	rep(i, n) {
		int a, b; (void)scanf("%d%d%lld", &a, &b, &c[i]);
		++b;
		v[2 * i] = { a,{1,i} }; v[2 * i + 1] = { b,{0,i} };
	}
	sort(v.begin(), v.end(), [&](pair<int, pii> p, pair<int, pii> q) {
		if (p.first == q.first) return p.second.first > q.second.first;
		else return p.first < q.first;
		});
	ll cur = 0;
	rep(i, 2 * n) {
		auto x = v[i];
		if (x.second.first == 1) {
			cur += c[x.second.second];
		}
		else {
			cur -= c[x.second.second];
		}
		d[i] = cur;
	}

	ll ans = 0;
	rep(i, 2 * n - 1) {
		auto x = min(C, d[i]);
		ans += x * (ll)(v[i + 1].first - v[i].first);
	}
	cout << ans << endl;

	return 0;
}

