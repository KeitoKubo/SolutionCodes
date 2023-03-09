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
	int n, m; cin >> n >> m;
	vector<int> a(n);
	ll sum = 0;
	rep(i, n) { (void)scanf("%d", &a[i]); sum += (ll)a[i]; }
	sort(a.begin(), a.end());
	vi b(n); copy(begin(a), end(a), begin(b));
	copy(b.begin(), b.end(), back_inserter(a));

	int key = a[0];
	ll ans = 0;
	ll cur = 0;
	for (auto P: a) {
		if (P == key || P == (key + 1) % m) {
			cur += (ll)P;
		}
		else {
			ans = max(ans, min(sum, cur)); cur = P;
		}
		key = P;
	}
	ans = max(ans, min(sum, cur));
	cout << sum-ans << endl;

	return 0;
}

