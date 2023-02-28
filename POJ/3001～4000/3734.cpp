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

//Union Find Tree
class DisjointSet {
public:
	vi rank, p, child; //rankはその木の深さ、pは親ノード

	DisjointSet() {}
	DisjointSet(int size) {
		rank.resize(size + 1, 0);
		p.resize(size + 1, 0);
		child.resize(size + 1, 0);
		repa(i, size) makeSet(i);
	}

	void makeSet(int x) {
		p[x] = x;
		rank[x] = 0;
		child[x] = 1;
	}

	int findSet(int x) {
		if (x != p[x]) p[x] = findSet(p[x]);
		return p[x];
	}

	int howmanychilds(int x) {
		return child[x];
	}

	bool same(int x, int y) {
		if (findSet(x) == findSet(y)) return true;
		else return false;
	}

	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
			child[x] += child[y];
		}
		else {
			p[x] = y; child[y] += child[x];
			if (rank[x] == rank[y]) rank[y]++;
		}
	}

	void unite(int x, int y) {
		link(findSet(x), findSet(y));
	}
};

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
const int M = 10007;

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
vector<vi> matpow(vector<vi> v, int n) { //vは正方行列
	vector<vi> mat(v.size(), vi(v.size()));
	rep(i, v.size()) mat[i][i] = 1;
	vector<vi> mat2(v.size(), vi(v.size()));
	mat2 = v;
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
	vector<vi>  A(4, vi(4));
	rep(i, 4) {
		rep(j, 4) {
			if (i == j) A[i][j] = 2;
			else if (i + j == 3) A[i][j] = 0;
			else A[i][j] = 1;
		}
	}
	
	int t; cin >> t;
	rep(i, t) {
		int n; cin >> n;
		vector<vi> B = matpow(A, n);
		cout << B[0][0] << endl;
	}

	return 0;

}

