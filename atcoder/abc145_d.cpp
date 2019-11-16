#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define FOR(e, c) for (auto &e : c)
#define SORT(v, n) sort(v, v + n);
#define vsort(v) sort(v.begin(), v.end());
#define rvisort(v) sort(v.begin(), v.end(), greater<int>());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
// #define int long long
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using ul = unsigned long;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }
 
const int INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;
 
long long rui(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b & 1)
      ans = ans * a % MOD;
    a = a * a % MOD;
    b /= 2;
  }
  return ans;
}

long long comb(long long a, long long b){
  long long ans = 1;
  for (long long i = a; i > a - b; i--){
    ans = ans * i % MOD;
  }
  for (long long i = 1; i <= b; i++){
    ans = (ans * rui(i, MOD - 2)) % MOD;
  }
  return ans;
}
 
signed main()
{
  ll x,y; cin>>x>>y;
  if((x+y)%3!=0){
    cout<<0<<endl;
    return 0;
  }
  ll a=(2*y-x)/3;
  ll b=(2*x-y)/3;
  
  if(x-2*b<0||y-2*a<0){
    cout<<0<<endl;
    return 0;
  }
  
  cout<<comb(a+b,a)<<endl;
}