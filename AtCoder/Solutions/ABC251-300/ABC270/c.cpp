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
int myprev[MX];
vector<int> e[MX];
int used[MX];

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n; cin >> n;
	int x, y; cin >> x >> y;
	rep(i, n-1) {
		int a, b; (void)scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	qi Q; Q.push(y);
	used[y] = true;
	while (!Q.empty()) {
		int p = Q.front(); (void)Q.pop();
		for (int t : e[p]) {
			if (!used[t]) {
				myprev[t] = p; used[t] = true; Q.push(t);
			}
		}
	}

	int cur = x;
	while (1) {
		cout << cur << " ";
		cur = myprev[cur];
		if (cur == y) break;
	}
	cout << y << endl;

	return 0;
}

