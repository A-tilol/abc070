#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;
typedef long long ll;

ll cost[100010];
vector< pair<int, ll> > v[100010];

// void bfs(int x){
//   FOR(i, 1, n-1){
//     if(cost[x] != 0) return;
     

//   }
// }
void dfs(int x, ll c){
  // dump(x);
  // if(cost[x] != -1) {cout << "exit" << endl; return;}
  if(cost[x] != -1) return;
  cost[x] = c;

  REP(i, v[x].size()){
    dfs(v[x][i].first, c + v[x][i].second);
  }
}

int main(){
  int n;
  cin >> n;

  int x, y, z;
  pair<int, int> p;
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
  dfs(k, 0);

  REP(i, q){
    cin >> x >> y;
    cout << cost[x] + cost[y] << endl;
  }

  // FOR(i, 1, n+1) cout << cost[i] << endl;
  
  return 0;
}