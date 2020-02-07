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

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}


map<int, int> prime_factor(int n)
{
  map<int, int> res;
  for (int i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
    {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1)
    res[n] = 1;
  return res;
}

long long mod_pow(long long x, long long n){
	if(n == 0) return 1;
	long long res = mod_pow(x*x % MOD, n / 2);
	if(n & 1) res = res*x % MOD;
	return res;
}

long long mod_inv(long long a, long long m) {
  long long b = m, u = 1, v = 0;
  while (b) {
    long long t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

// 参考
// https://atcoder.jp/contests/abc152/submissions/9607026

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int n; cin>>n;
  vll a(n);
  rep(i,n) cin>>a[i];
  
  map<int,int> pf;
  rep(i,n){
    map<int,int> tmp=prime_factor(a[i]);
    for(auto j: tmp){
      pf[j.first]=max(pf[j.first],j.second);
    }
  }
  ll l=1;
  for(auto i: pf){
    l=l*mod_pow(i.first,i.second)%MOD;
  }
  int ans=0;
  rep(i,n){
    ans+=l*mod_inv(a[i],MOD)%MOD;
    ans%=MOD;
  }
  
  cout<<ans<<endl;
  
}