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
int a[11][11];
int h, w;

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	cin >> h >> w;
	rep(i, h)rep(j, w) (void)scanf("%d", &a[i][j]);
	int ans = 0;
	for (int x = 0; x < (int)pow(2, h + w - 2); x++) {
		int count = 0; int y = x;
		while (y > 0) {
			if (y & 1) ++count;
			y >>= 1;
		}
		if (count != w - 1) continue;
		y = x; map<int, int> mp; bool flag = true;
		mp[a[0][0]] = true;
		int X = 0, Y = 0;
		rep(i, h + w - 2) {
			if (y & 1) {
				++X;
			}
			else {
				++Y;
			}
			if (mp[a[Y][X]] == 1) flag = false;
			mp[a[Y][X]] = 1;
			y >>= 1;
		}
		if (flag) ++ans;
	}
	cout << ans << endl;

	return 0;
}

