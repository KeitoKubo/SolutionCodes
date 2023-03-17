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
	int n, q; cin >> n >> q;
	vi a(n);
	rep(i, n)(void)scanf("%d", &a[i]);

	const int Ma = 200005;
	vi cnt(Ma);
	vi l(q), r(q), qs(q); //qsは区間をソートしたときのindex順を保管するための配列
	rep(i, q) { (void)scanf("%d%d", &l[i], &r[i]); --l[i]; }
	rep(i, q) qs[i] = i;
	int D = max(1, n / ((int)sqrt(q)));
	sort(qs.begin(), qs.end(), [&](int i, int j) {
		if (r[i] / D == r[j] / D) return l[i] < l[j]; //同じパケット内に存在する
		else return r[i] < r[j];
		});

	ll now = 0;
	auto c3 = [&](ll n) {return n * (n - 1) * (n - 2) / 6; };
	auto add = [&](int i, int x = 1) {
		now -= c3(cnt[a[i]]);
		cnt[a[i]] += x;
		now += c3(cnt[a[i]]);
	};
	auto del = [&](int i) {add(i, -1); };

	vector<ll> ans(q);
	int li = 0, ri = 0;
	for (int qi : qs) {
		int ln = l[qi], rn = r[qi];
		while (ri < rn) add(ri++);
		while (li > ln) add(--li);
		while (ri > rn) del(--ri);
		while (li < ln) del(li++);
		ans[qi] = now;
	}
	for (ll x : ans) cout << x << endl;

	return 0;
}

