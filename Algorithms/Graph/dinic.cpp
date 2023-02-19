#include <vector>
#include <iostream>
#include <queue>

using namespace std;
#define infi (1<<20)

const int MAX_V = 50;

struct edge{int to,cap,rev;}; //辺を記述 to:行き先,cap:容量,rev:逆辺の位置
int level[MAX_V]; //sからの距離
int iter[MAX_V]; //どこまで調べ終わったか
vector<edge> G[MAX_V];//辺の隣接リスト表現

void add_node(int from, int to, int cap){
    edge e = {to,cap,G[to].size()};
    G[from].push_back(e);
    e = {from, cap, G[from].size()-1};
    G[to].push_back(e);
}

void bfs(int s){
  memset(level,-1,sizeof(level));
  queue<int> Q;
  Q.push(s); level[s]=0;
  while(!Q.empty()){
    int v=Q.front(); Q.pop();
    for(int i=0;i<G[v].size();i++){
      edge& e = G[v][i];
      if(e.cap >0 && level[e.to]<0){
        level[e.to] = level[v]+1;
        Q.push(e.to);
      }
    }
  }
}

int dfs(int v, int t, int f){
  if(v==t) return f;
  for(int& i=iter[v];i<G[v].size();i++){
    edge& e=G[v][i];
    if(e.cap>0 && level[v]<level[e.to]){
      int d = dfs(e.to, t, min(f,e.cap));
      if(d>0){
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t){
  int flow=0;
  while(true){
    bfs(s);
    if(level[t]<0) return flow; //sからtへのフローが存在しなくなった
    memset(iter,0,sizeof(iter));
    int f;
    while(f=dfs(s,t,infi) >0){
      flow += f;
    }
  }
}

int main(){
  
}