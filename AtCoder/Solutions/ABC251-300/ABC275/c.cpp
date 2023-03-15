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
	vs vec(10);
	rep(i, 9) cin >> vec[i];

	int ans = 0;
	rep(i, 81) {
		int sy = i / 9, sx = i % 9;
		if (vec[sy][sx] == '#') {
			for (int j = i + 1; j < 81; ++j) {
				int ty = j / 9, tx = j % 9;
				if (vec[ty][tx] == '#') {
					if (ty > sy && tx <= sx) {
						int px = sx + ty - sy, py = sy + sx - tx;
						int qx = tx + ty - sy, qy = ty + sx - tx;
						if (px < 9 && qx < 9 && py < 9 && qy < 9) {
							if (vec[py][px] == '#' && vec[qy][qx] == '#') ++ans;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}

