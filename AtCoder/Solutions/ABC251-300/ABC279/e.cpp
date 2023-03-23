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
	int n, m; cin >> n >> m;
	vi a(m + 1); //1-indexed
	vi b(m + 1); // b[i] := i番目までのあみだを用いたときの1の位置
	vi ans(m + 1);
	repa(i, m) (void)scanf("%d", &a[i]);

	b[0] = 1;
	repa(i, m) {
		if (a[i] == b[i - 1]) {
			b[i] = b[i - 1] + 1;
		}
		else if (a[i] + 1 == b[i - 1]) {
			b[i] = b[i - 1] - 1;
		}
		else b[i] = b[i - 1];
	}

	vi dp(n + 1); 
	repa(i, n) dp[i] = i;
	ans[m] = b[m - 1];
	for (int i = m - 1; i >= 1; --i) { //i本目のあみだを削除したときの1の位置を求める
		//dpテーブルを更新
		int s = a[i + 1], t = a[i + 1] + 1;
		int temp = dp[s];
		dp[s] = dp[t];
		dp[t] = temp;
		//ans
		int pos = b[i - 1];
		ans[i] = dp[pos];
	}

	repa(i, m) cout << ans[i] << endl;

	return 0;
}

