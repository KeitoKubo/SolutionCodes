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
	int n; cin >> n;
	dsu ds(2 * n + 1);
	unordered_map<int, int> mp;
	int num = 1;
	rep(i, n) {
		int a, b;
		(void)scanf("%d%d", &a, &b);
		if (!mp.count(a)) { mp[a] = num++; }
		if (!mp.count(b)) { mp[b] = num++; }
		ds.merge(mp[a], mp[b]);
	}

	int ans = 1;
	for (auto x : mp) {
		if (ds.same(mp[1], x.second)) ans = max(ans, x.first);
	}
	cout << ans << endl;

	return 0;
}

