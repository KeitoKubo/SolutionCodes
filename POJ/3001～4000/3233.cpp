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
const int MX = 2e5 + 2;
int M;

vector<vi> matmul(vector<vi> v1, vector<vi> v2) {
	vector<vi> mat(v1.size(), vector<int>(v2[0].size()));
	rep(i, v1.size()) {
		rep(k, v2.size()) {
			rep(j, v2[0].size()) {
				mat[i][j] = (mat[i][j] + v1[i][k] * v2[k][j]) % M;
			}
		}
	}
	return mat;
}

//vのn乗を返す
vector<vi> matpow(vector<vi> v, int m) { //vは正方行列
	vector<vi> mat(v.size(), vi(v.size()));
	rep(i, v.size()) mat[i][i] = 1;
	vector<vi> mat2(v.size(), vi(v.size()));
	mat2 = v;
	int n = m;
	while (n > 0) {
		if (n & 1) mat = matmul(mat, mat2);
		mat2 = matmul(mat2, mat2);
		n >>= 1;
	}
	return mat;
}

int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	int n, k; cin >> n >> k >> M;
	vvi A = vvi(n, vi(n));
	rep(i, n) { rep(j, n) (void)scanf("%d", &A[i][j]); }

	vvi B = vvi(2 * n, vi(2 * n));
	rep(i, 2 * n) {
		rep(j, 2 * n) {
			if (i < n && j < n) {
				if (i == j) B[i][j] = 1;
				else B[i][j] = 0;
			}
			else if (i < n) {
				B[i][j] = 0;
			}
			else if (j < n) {
				if (i - n == j) B[i][j] = 1;
				else B[i][j] = 0;
			}
			else {
				B[i][j] = A[i - n][j - n];
			}
		}
	}
	vvi B_n = matpow(B, k);
	vvi C(2 * n, vi(n));

	rep(i, 2 * n) {
		rep(j, n) {
			if (i < n) C[i][j] = A[i][j];
			else C[i][j] = 0;
		}
	}

	vvi ans = matmul(B_n, C);

	for (int i = n; i < 2 * n; i++) {
		rep(j, n) {
			if (j == n - 1) cout << ans[i][j] << endl;
			else cout << ans[i][j] << " ";
		}
	}

	return 0;

}

