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
	int H, W, N, h, w; std::cin >> H >> W >> N >> h >> w;
	unordered_map<int, vector<pii>> mp;
	int all = 0;
	repa(i, H)repa(j, W) {
		usi x; (void)scanf("%d", &x);
		mp[x].emplace_back(i, j);
	}

	vector<vi> imosTable(H - h + 2, vi(W - w + 2));
	rep(i, H - h + 2)rep(j, W - w + 2) {
		imosTable[i][j] = 0;
    }
	for (auto [A,yx] : mp) {
		//calculate [lx,rx) x [ly,ry) area which paints all Number-i grid
		int lx = 0, rx = W - w + 1, ly = 0, ry = H - h + 1;
		for (auto [y,x] : yx) {
			lx = max(lx, x - w);
			ly = max(ly, y - h);
			rx = min(rx, x);
			ry = min(ry, y);
		}
		if (lx < rx && ly < ry) {
			imosTable[ly][lx]++;
			imosTable[ry][lx]--;
			imosTable[ly][rx]--;
			imosTable[ry][rx]++;
		}
	}

	//calculate cur-sum with imos-method
	rep(y, H - h + 1) {
		repa(x, W - w) {
			imosTable[y][x] += imosTable[y][x - 1];
		}
	}
	repa(y, H - h) {
		rep(x, W - w + 1) {
			imosTable[y][x] += imosTable[y - 1][x];
		}
	}

	//print
	rep(y, H - h + 1) {
		rep(x, W - w + 1) {
			cout << mp.size() - imosTable[y][x] << " ";
		}
		printf("\n");
	}

	return 0;
}

