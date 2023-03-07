#define _USE_MATH_DEFINES
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

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

ll f(ll x, int q) {
	int c = 0;
	for (ll y = x;; y += x) {
		int p = 0;
		ll z = y;
		while (z % x == 0) {
			z /= x; ++p;
		}
		c += p;
		if (c >= q) { return y; }
	}
}

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	ll K; cin >> K;
	int k;
	for (ll i = 1;; i++) {
		if ((ll)i * (ll)i > K) {
			k = i - 1; break;
		}
	}
	vector<pair<ll,int>> vec;
	int index = 2;
	while (K > 1 && index <= k) {
		if (K % (ll)index == 0) {
			int count = 0;
			while (K % (ll)index == 0) {
				K /= (ll)index; ++count;
			}
			vec.emplace_back((ll)index, count);
		}
		++index;
	}
	if (K != 1) vec.emplace_back(K, 1);

	ll ans = -1;
	rep(i, vec.size()) {
		ll x = f(vec[i].first, vec[i].second);
		ans = max(ans, x);
	}
	cout << ans << endl;

	return 0;
}

