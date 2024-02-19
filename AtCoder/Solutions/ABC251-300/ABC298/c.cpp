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

#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define repa(i,n) for(int i = 1; i <= (int)n; i++)
#define irep(i,n) for(int i = (int)n - 1;i >= 0; i--)
#define irepa(i,n) for(int i = (int)n; i >= 1; i--)

//constant numbers
const int MXint = 2e5;
#define infi 2147483647
#define infl 9223372036854775806
#define MOD  1000000007
#define EPS 0.0000000001

using Mint = atcoder::modint998244353;
vector<Mint> fact(MXint);
struct modinv {
	int n; vector<Mint> d;
	modinv() : n(2), d({ 0,1 }) {}
	Mint operator()(int i) {
		while (n <= i) d.push_back(-d[Mint::mod() % n] * (Mint::mod() / n)), ++n;
		return d[i];
	}
	Mint operator[](int i) const { return d[i]; }
} invs;
struct modfact {
	int n; vector<Mint> d;
	modfact() : n(2), d({ 1,1 }) {}
	Mint operator()(int i) {
		while (n <= i) d.push_back(d.back() * n), ++n;
		return d[i];
	}
	Mint operator[](int i) const { return d[i]; }
} facts;
struct modfactinv {
	int n; vector<Mint> d;
	modfactinv() : n(2), d({ 1,1 }) {}
	Mint operator()(int i) {
		while (n <= i) d.push_back(d.back() * invs(n)), ++n;
		return d[i];
	}
	Mint operator[](int i) const { return d[i]; }
} ifacts;
Mint comb(int n, int k) {
	if (n < k || k < 0) return 0;
	return facts(n) * ifacts(k) * ifacts(n - k);
}

//---------------------------------------------------

const int MX = int(2e5) + 1;
vector<int> vec[MX];
map<pii, bool> mp_exist;
map<int, std::vector<int>> mp_arr;

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int N, Q;
	cin >> N >> Q;
	rep(index, Q) {
		char c;
		int i;
		cin >> c >> i;
		if (c == '1') {
			int j; cin >> j;
			//insertion
			auto ite = lower_bound(vec[j].begin(), vec[j].end(), i);
			vec[j].insert(ite, i);
			//map operation
			if (mp_exist[std::make_pair(i, j)] == false) {
				vi v_cur = mp_arr[i];
				auto ite = lower_bound(v_cur.begin(), v_cur.end(), j);
				v_cur.insert(ite, j);
				mp_arr[i] = v_cur;
			}
			mp_exist[std::make_pair(i, j)] = true;
		}
		else if (c == '2') {
			vi v_cur = vec[i];
			rep(index_2, size(v_cur) - 1) {
				cout << v_cur[index_2] << " ";
			}
			cout << v_cur[size(v_cur) - 1] << endl;
		}
		else if (c == '3') {
			vi v_cur = mp_arr[i];
			rep(index_2, size(v_cur) - 1) {
				cout << v_cur[index_2] << " ";
			}
			cout << v_cur[size(v_cur) - 1] << endl;
		}
		else {
			printf("Invalid key!\n");
		}
	}
	

	return 0;
}

