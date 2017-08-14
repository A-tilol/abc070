#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

#define _BFS 1
// #define _DFS 1

using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;

ll cost[100010];
vector< pair<int, ll> > v[100010];

void bfs(int k){
  queue< pil > q;
  q.push(pil(k, 0));

  pil p;
  int x, y;
  while(!q.empty()){
    p = q.front();
    q.pop();

    x = p.first;
    REP(i, v[x].size()){
      y = v[x][i].first;
      if(cost[y] != -1) continue;
      cost[y] = p.second + v[x][i].second;
      q.push(pil(y, cost[y]));
    }

  }
}

void dfs(int x, ll c){
  // dump(x);
  // if(cost[x] != -1) {cout << "exit" << endl; return;}
  if(cost[x] != -1) return;
  cost[x] = c;

  REP(i, v[x].size()){
    dfs(v[x][i].first, c + v[x][i].second);
  }
}

#ifdef _BFS
int main(){
  int n;
  cin >> n;

  int x, y, z;
  pair<int, ll> p;
  REP(i, n-1){
    cin >> x >> y >> z;
    p.first = y;
    p.second = z;
    v[x].push_back(p);
    p.first = x;
    v[y].push_back(p);
  }

  int q, k;
  cin >> q >> k;

  REP(i, n+1) cost[i] = -1;
  bfs(k);

  REP(i, q){
    cin >> x >> y;
    cout << cost[x] + cost[y] << endl;
  }

  return 0;
}
#endif

#ifdef _DFS
int main(){
  int n;
  cin >> n;

  int x, y, z;
  pair<int, ll> p;
  REP(i, n-1){
    cin >> x >> y >> z;
    p.first = y;
    p.second = z;
    v[x].push_back(p);
    p.first = x;
    v[y].push_back(p);
  }

  int q, k;
  cin >> q >> k;

  REP(i, n+1) cost[i] = -1;
  dfs(k);

  REP(i, q){
    cin >> x >> y;
    cout << cost[x] + cost[y] << endl;
  }

  // FOR(i, 1, n+1) cout << cost[i] << endl;
  
  return 0;
}
#endif