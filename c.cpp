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
#define SWAP(a, b) ((a)!=(b)?(a)^=(b)^=(a)^=(b):(a)=(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  ll value = gcd(a, b);
  return a/value * b;
}

int main(){
  int n;
  cin >> n;

  ll ans = 1;
  REP(i, n){
    ll t;
    cin >> t;

    if(ans < t) SWAP(ans, t);
    ans = lcm(ans, t);
  }

  cout << ans << endl;
  
  return 0;
}