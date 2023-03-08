#define _USE_MATH_DEFINES
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<string, bool> msb;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;
typedef complex<double> cmp;

#define infi 2147483647
#define infl 9223372036854775806
#define MOD  1000000007
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repa(i,n) for(int i=1;i<=(int)n;i++)
#define irep(i,n) for(int i=(int)n-1;i>=0;i--)


//sort vector<pii> by second element
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

//---------------------------------------------------
const int MX = 2e5 + 2;


int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	map<int, ll> mp;
	int n; cin >> n;
	vector<ll> a(n+1);
	repa(i, n) { (void)scanf("%lld", &a[i]); }
	int q; cin >> q;
	ll num = -1;
	rep(i, q) {
		int c; cin >> c;
		if (c == 1) {
			ll x; (void)scanf("%lld", &x);
			num = x;
			mp.clear();
		}
		else if (c == 2) {
			int p; ll x; (void)scanf("%d%lld", &p, &x);
			mp[p] += x;
		}
		else {
			int p; (void)scanf("%d", &p);
			if (num == -1) cout << a[p] + mp[p] << endl;
			else cout << num + mp[p] << endl;
		}
	}

	return 0;
}

