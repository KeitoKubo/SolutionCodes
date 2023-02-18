#include <vector>
#include <iostream>

using namespace std;

#define MAX_V 50
#define infi (1<<20)

struct edge { int to, cap, rev; };

vector<edge> G[MAX_V];
bool used[MAX_V];

void add_edge(int _from, int _to, int cap){
	edge e = { _to, cap, G[_to].size() }; G[_from].push_back(e);
	e = { _from, 0, (int)G[_from].size() - 1 }; G[_to].push_back(e);
}

int dfs(int v, int t, int f) {//sからtへ移動可能ならそのルートの最大流量を返し、不可能なら0を返す。
	if (v == t) return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge& e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d; //逆辺の容量はdだけ増加する
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t) { //O(F|E|) F:流量の最大値
	int flow = 0;
	while (true) { //パスがなくなるまでdfsを繰り返す
		memset(used, 0, sizeof(used));
		int f = dfs(s, t, infi);
		if (f == 0) return flow;
		flow += f;
	}
}

int main() {
	

	return 0;
}