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
	string s; cin >> s;
	int n = s.length();
	vector<vector<int>> vec(n + 1, vector<int>(10));
	rep(i, 10) vec[0][i] = 0;
	repa(i, n) {
		int c = s[i - 1] - '0';
		rep(j, 10) {
			vec[i][j] = vec[i - 1][j];
		}
		vec[i][c]++;
		vec[i][c] %= 2;
	}

	vector<int> a(1 << 10);
	rep(i, 1 << 10) a[i] = 0;
	rep(i, n + 1) {
		int x = 0;
		rep(j, 10) {
			x += (int)pow(2, j) * vec[i][j];
		}
		++a[x];
	}

	ll ans = 0;
	for (int x : a) {
		ans += (ll)x * (ll)(x - 1) / 2;
	}
	cout << ans << endl;

	return 0;
}

