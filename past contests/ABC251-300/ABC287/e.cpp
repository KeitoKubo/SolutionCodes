#define _USE_MATH_DEFINES
#include <iostream>                         // cout, endl, cin
#include <cstdio>                           // printf, scanf
#include <string>                           // string, to_string, stoi
#include <algorithm>                        // min, max, swap, lower_bound, upper_bound
// & stable_sort, sort, reverse
#include <cmath>                            //sin(rad),cos,tan, abs, pow, sqrt, cbrt,  exp, log, log10, log2
#include <utility>                          // pair, make_pair
#include <map>                              // map
#include <unordered_map>
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


int main() {
	//(void)scanf("%d",& );
	//(void)scanf("%d%d",& ,& );
	unordered_map<string, int> map_identify;
	unordered_map<string, int> map_counter;
	vector<string> vec;
	vector<string> vec_forsort;
	int n; cin >> n;
	rep(i, n) {
		//string s; cin >> s; vec.push_back(s); vec_forsort.push_back(s); map_counter[s]++;
		char s[500001]; (void)scanf("%s", s); vec.emplace_back(s); vec_forsort.emplace_back(s); map_counter[string(s)]++;
	}
	sort(vec_forsort.begin(), vec_forsort.end());
	rep(i, n) {
		map_identify[vec_forsort[i]] = i;
	}

	rep(i, n) {
		string key = vec[i];
		if (map_counter[key] >= 2) cout << key.length() << endl;
		else {//keyに相当する文字列はvecの中に1つしか存在しないはず
			int place = map_identify[key];
			int ansP = 0, ansA = 0;
			string key_nextP = "", key_nextA = "";
			if (place != n-1) {
				key_nextA = vec_forsort[place + 1];
				int len = min(key.length(), key_nextA.length());
				ansA = len;
				rep(j, len) {
					if (key[j] != key_nextA[j]) {
						ansA = j; break;
					}
				}
			}
			if (place != 0) {
				key_nextP = vec_forsort[place - 1];
				int len = min(key.length(), key_nextP.length());
				ansP = len;
				rep(j, len) {
					if (key[j] != key_nextP[j]) {
						ansP = j; break;
					}
				}
			}
			cout << max(ansA, ansP) << '\n';
		}
	}


	return 0;
}

