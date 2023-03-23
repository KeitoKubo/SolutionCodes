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
	int n; string t;
	cin >> n >> t;
	string a = t.substr(0, n);
	string b = t.substr(n);
	(void)reverse(b.begin(), b.end());

	string x = a + b;
	string y = b + a;

	vi zx = atcoder::z_algorithm(x);
	vi zy = atcoder::z_algorithm(y);

	rep(i, n) {
		if (i && zx[n * 2 - i] != i) continue;
		int j = n - i;
		if (zy[n * 2 - j] != j) continue;
		string p = a.substr(0, i);
		reverse(a.begin(), a.end());
		string q = a.substr(0, j);
		cout << p + q << endl;
		cout << i << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}

