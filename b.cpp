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

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if(c > b || a > d){
    cout << 0 << endl;
  }
  else{
    cout << MIN(b, d) - MAX(a, c) << endl;
  }
  
  return 0;
}