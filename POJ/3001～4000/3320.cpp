#define _USE_MATH_DEFINES
#include <iostream>                         // cout, endl, cin
#include <cstdio>                           // printf, scanf
#include <string>                           // string, to_string, stoi
#include <algorithm>                        // min, max, swap, lower_bound, upper_bound, stable_sort, sort, reverse
#include <cmath>                            //sin(rad),cos,tan, abs, pow, sqrt, cbrt,  exp, log, log10, log2
#include <utility>                          // pair, make_pair
#include <map>                              // map
#include <set>                              // set
#include <vector>                           // vector
#include <queue>                            // queue, priority_queue
#include <stack>                            // stack
#include <list>                             // list
#include <deque>                            // deque
#include <iomanip>
#include <numeric>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

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

#define infi 2147483647
#define infl 9223372036854775806
#define MOD  1000000007
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repa(i,n) for(int i=1;i<=(int)n;i++)
#define irep(i,n) for(int i=(int)n-1;i>=0;i--)


//---------------------------------------------------
const int MX = 1e6 + 2;
int a[MX];
map<int, int> mp;

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n; cin >> n;
	rep(i, n) (void)scanf("%d", &a[i]);

	int m = 0;
	rep(i, n) {
		if (mp[a[i]] == 0) ++m;
		mp[a[i]]++;
	}

	mp.clear();
	int s = 0, t = 0; //find the first sufficient sequence
	int u = 0;
	rep(i, n) {
		if (mp[a[i]] == 0)++u;
		++mp[a[i]];
		if (u == m) { t = i; break; }
	}
	rep(i, n) {
		if (mp[a[i]] == 1) break;
		--mp[a[i]]; ++s;
	}
	++t;
	int ans = t - s;
	while (1) {
		while (s<n) { //element to read
			if (--mp[a[s++]] == 0) break;
		}
		bool flag = false;
		while (t < n) {
			if (mp[a[t++]]++ == 0) { flag = true; break; }
		}
		if (flag) ans = min(ans, t - s + 1);
		if (t == n) break;
	}
	cout << ans << endl;
	return 0;
}

