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

int lcm(int x, int y) {
	if (x % y == 0) return y;
	else return lcm(y, x % y);
}

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n; cin >> n;
	int num = -1;
	int count = 0;
	int  L = -1; 
	bool flag = true;
	rep(none, n) {
		int x;  cin >> x;
		if (num == -1) L = x;
		else L = lcm(L, x);
		while (x % 2 == 0) { x /= 2; ++count; }
		while (x % 3 == 0) { x /= 3; ++count; }
		if (num == -1) { num = x; }
		else {
			if (num != x) flag = false;
		}
	}

	if (!flag) cout << -1 << endl;
	else {
		int y = 0;
		while (L % 2 == 0) { L /= 2; ++y; }
		while (L % 3 == 0) { L /= 3; ++y; }
		cout << count - y * n << endl;
	}

	return 0;
}

