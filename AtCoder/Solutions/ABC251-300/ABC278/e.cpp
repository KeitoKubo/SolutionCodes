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
const int MX = 302;
int dp[MX][MX]; //solving problem at (i,j)
int H, W, h, w, n;
int g[MX][MX];
map<int, int> mp;

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	(void)scanf("%d%d%d%d%d", &H, &W, &n, &h, &w);
	int num = 0;
	rep(i, H)rep(j, W) { 
		(void)scanf("%d", &g[i][j]); 
		if (mp[g[i][j]]++ == 0) ++num;
	}

	rep(i, h)rep(j, w) {
		if (--mp[g[i][j]] == 0) --num;
	}
	dp[0][0] = num;
	rep(j, W - w + 1)rep(i, H - h + 1) {
		if (i == 0 && j == 0) continue;
		int cur;
		if (i == 0) {//recalculate
			cur = dp[H - h][j - 1];
			for (int y = H - h; y <= H - 1; y++) {
				for (int x = j - 1; x <= j + w - 2; x++) {
					if (mp[g[y][x]]++ == 0) ++cur;
				}
			}
			for (int y = 0; y < h; y++) {
				for (int x = j; x <= j + w - 1; x++) {
					if (--mp[g[y][x]] == 0) --cur;
				}
			}
		}
		else {//vertical dp
			cur = dp[i - 1][j];
			for (int x = j; x < j + w; x++) {
				if (mp[g[i - 1][x]]++ == 0) ++cur;
			}
			for (int x = j; x < j + w; x++) {
				if (--mp[g[i + h - 1][x]] == 0) --cur;
			}
		}
		dp[i][j] = cur;
	}

	rep(i, H - h + 1) {
		rep(j, W - w + 1) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}

