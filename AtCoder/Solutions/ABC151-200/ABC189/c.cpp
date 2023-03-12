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
	int n; cin >> n;
	vi a(n);
	rep(i, n) (void)scanf("%d", &a[i]);

	int ans = -1;
	for (int i = 0; i < n; ++i) {
		int sum = a[i];
		int x = a[i];
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < x) {
				ans = max(sum, ans);
				sum = a[j] * (j - i + 1);
				x = a[j];
			}
			else {
				sum += x;
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;

	return 0;
}

