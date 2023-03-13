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
const unsigned MX = 1e6 + 2;
int used[MX]; //used[i*w+j] := 既に[i,j]を調べたか。



int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int h, w; cin >> h >> w;
	vector<string> vec(h);
	rep(i, h) cin >> vec[i];

	int sx = -1, sy = -1;
	rep(i, h)rep(j, w) {
		if (vec[i][j] == 'S') { sx = j; sy = i; break; }
	}

	queue<pair<pii,int>> Q; //現在いるマス、現在の経路長
	pair<pii, int> S = { {sx,sy},0 };
	Q.push(S);
	bool ans = false;


	return 0;
}

