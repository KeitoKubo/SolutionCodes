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
ll dp[101][101][101];
int a[101];

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int N, K, D; cin >> N >> K >> D;
	repa(i,N) (void)scanf("%d", &a[i]);

	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = 0;
	for (int j = 1; j <= min(N,K) + 1; ++j) {
		for (int i = j; i <= N; ++i) {
			for (int k = 0; k < D; ++k) {
				if (dp[i - 1][j - 1][k] < 0) continue;
				int x = (a[i] + k) % D;
				dp[i][j - 1][k] = max(dp[i - 1][j - 1][k], dp[i][j - 1][k]); //何も選択しない
				if(j != min(N, K) + 1)dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j - 1][k] + (ll)a[i]); //選択できるなら更新
			}
		}
	}
	cout << dp[N][K][0] << endl;

	return 0;
}

