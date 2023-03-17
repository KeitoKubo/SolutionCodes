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
const int MXN = 1e4;
int dpx[MXN * 2 + 2];
int dpy[MXN * 2 + 2];

int main() {
	int n; cin >> n;
	int ax, ay; cin >> ax >> ay;
	vi x, y;
	rep(i, n) {
		int p; (void)scanf("%d", &p);
		if (i == 0) { dpx[MXN + p] = true; continue; }
		if (i % 2 == 0) x.push_back(p);
		else y.push_back(p);
	}
	
	bool flx = false, fly = false;
	dpy[MXN] = true; //0→MXN, -MXN→0
	for (int q : x) {
		vi X;
		rep(i, MXN * 2 + 2) {
			if (dpx[i]) { dpx[i] = false; dpx[i - q] = true; X.push_back(i + q); }
		}
		for (int r : X) dpx[r] = true;
	}
	if (dpx[MXN + ax]) flx = true;

	for (int q : y) {
		vi Y;
		rep(i, MXN * 2 + 2) {
			if (dpy[i]) { dpy[i] = false; dpy[i - q] = true; Y.push_back(i + q); }
		}
		for (int r : Y) dpy[r] = true;
	}
	if (dpy[MXN + ay]) fly = true;

	if (fly && flx) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
