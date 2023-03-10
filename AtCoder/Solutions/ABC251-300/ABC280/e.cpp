#define _USE_MATH_DEFINES
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

using Mint = atcoder::modint998244353;

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

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n, p; cin >> n >> p;
	vector<Mint> vec(n + 1);
	vec[0] = Mint(0);
	Mint crit = Mint(p) / 100, norm = 1 - crit;
	for (int i = 1; i <= n; i++) {
		vec[i] = vec[i - 1] * norm + vec[max(0, i - 2)] * crit + Mint(1);
	}
	cout << vec[n].val() << endl;

	return 0;
}

