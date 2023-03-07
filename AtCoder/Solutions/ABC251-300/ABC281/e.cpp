#define _USE_MATH_DEFINES
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

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
int n, m, k;

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	cin >> n >> m >> k;
	vi a(n);
	rep(i,n){ (void)scanf("%d", &a[i]); }

	vector<pii> vec;
	ll sum = 0;
	priority_queue<pii> A, B; //B.first には -1 をかける
	vi c(n); //i番目の要素がAに含まれているなら0,Bに含まれているなら1

	rep(i, m) {
		vec.emplace_back(a[i], i);
	}
	sort(vec.begin(), vec.end());
	rep(i, k) { A.push(vec[i]); sum += (ll)vec[i].first; c[vec[i].second] = 0; }
	for (int i = k; i < m; i++) { pii x = make_pair(vec[i].first * (-1), vec[i].second); B.push(x); c[x.second] = 1; }
	cout << sum << endl;

	for (int i = 1; i <= n - m; ++i) { //a continuous subsequence of length m starting at i
		//add i+m-1 th element
		int add_A = 0, add_B = 0;
		if (a[i + m - 1] > A.top().first) { B.push(make_pair(a[i + m - 1] * (-1), i + m - 1)); c[i + m - 1] = 1; add_B++; }
		else { A.push(make_pair(a[i + m - 1], i + m - 1)); c[i + m - 1] = 0; sum += (ll)a[i + m - 1]; add_A++; }
		//delete i-1 th element
		while (!B.empty() && B.top().second < i) B.pop();
		while (!A.empty() && A.top().second < i) A.pop();
		if (c[i - 1] == 0) {
			add_B++; sum -= (ll)a[i - 1];
		}
		else {
			add_A++;
		}
		if (add_A == 2) {//Aから1つBにもっていく
			pii X = A.top(); A.pop(); sum -= (ll)X.first;
			pii Y = make_pair(X.first * (-1), X.second);
			B.push(Y); c[Y.second] = 1;
		}
		if (add_B == 2) {//Bから1つAにもっていく
			pii X = B.top(); B.pop();
			pii Y = make_pair(X.first * (-1), X.second);
			A.push(Y); sum += (ll)Y.first; c[Y.second] = 0;
		}
		cout << sum << endl;
	}
	return 0;
}

