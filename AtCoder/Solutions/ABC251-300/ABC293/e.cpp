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
	ll a, x, m; cin >> a >> x >> m;
	ll y = sqrtl(x);
	ll ax = 1;
	rep(i, y) {
		ax = (ax * a) % m;
	}
	ll s = 0; ll cur = 1;
	rep(i, y) {
		s = (s + cur) % m;
		cur = (cur * a) % m;
	}
	ll sum = 0;
	cur = 1;
	rep(i, y) {
		ll p = (cur * s) % m;
		sum = (sum + p) % m;
		cur = (cur * ax) % m;
	}
	for (ll X = y * y; X < x; ++X) {
		sum = (sum + cur) % m;
		cur = (cur * a) % m;
	}

	cout << sum << endl;


	return 0;
}

