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
const unsigned MX = 2002;
bool isexist[MX];
using Mint = atcoder::modint998244353;
Mint cmb(int a, int b) {
	Mint x = Mint(1);
	repa(i, a) x *= Mint(i);
	repa(i, b) x /= Mint(i);
	repa(i, a - b) x /= Mint(i);
	return x;
}

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n, k, m; cin >> n >> k >> m;
	vi a(n);
	int cnt = 0;
	rep(i, n) {
		cin >> a[i];
		if (a[i] == 0) ++cnt;
		isexist[a[i]] = true;
	}
	sort(a.begin(), a.end());

	Mint ans = Mint(0);
	repa(X, m) {
		auto ite = lower_bound(a.begin(), a.end(), X);
		int A = ite - a.begin(); //X未満の要素の個数
		if (A > k) continue;

	}

	return 0;
}

