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


int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n; cin >> n;
	std::map<int, int> mp; // detect more-than-one chapter
	vi a(n), b(n);
	rep(i, n) (void)scanf("%d", &a[i]);
	if (n == 1 && a[0] != 1) { cout << 0 << endl; return 0; }
	std:: sort(a.begin(), a.end());
	std::copy(a.begin(), a.end(), b.begin());
	b.erase(std::unique(b.begin(), b.end()), b.end());

	int rm = a.size() - b.size(); //num of duplicated books
	int cur = 1;
	while (rm >= 2) {
		if (!mp.count(cur)) { rm -= 2; mp[cur] = 1; }
		++cur;
	}
	while (mp[cur] > 0) ++cur;
	if (rm == 1) b.push_back(infi);
	for (auto P : mp) mp[P.first] = 1;

	auto ite = b.end();
	while (true) {
		if (mp.count(cur)) { ++cur; continue; }
		if (ite == b.begin() || ite == (b.begin() + 1) || *(ite - 2) < cur) break;
		mp[*(--ite)]--; mp[*(--ite)]--; mp[cur++]++;
	}

	if (!mp.count(cur)) --cur;
	cout << cur << endl;

	return 0;
}

