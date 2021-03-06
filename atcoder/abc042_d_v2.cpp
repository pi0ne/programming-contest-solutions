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

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) { return a / GCD(a, b)* b; }

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

const int maxn=200010;
ll fact[maxn];
ll invfact[maxn];

ll nCr(ll n, ll r){
  ll res=fact[n];
  (res*=invfact[r])%=MOD;
  (res*=invfact[n-r])%=MOD;
  return res;
}

long long modpow(long long a, long long n, long long mod) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    (a *= a) %= mod;
    n >>= 1;
  }
  return res;
}

long long modinv(long long a, long long mod) {
  return modpow(a, mod - 2, mod);
}

signed main()
{
  int h,w,a,b;
  cin>>h>>w>>a>>b;
  cin.tie( 0 ); ios::sync_with_stdio( false );
  fact[0]=1;
  for(int i=1; i<=maxn; i++){
    fact[i]=(fact[i-1]*i)%MOD;
  }
  rep(i,maxn){
    invfact[i]=modinv(fact[i], MOD);
  }
  ll ans=0;
  for(int i=1; i<=w-b; i++){
    ll tmp = (nCr(h-a-1 + b-1+i, h-a-1) * nCr(a-1 + w-b-i, a-1)) % MOD;
    (ans+=tmp) %= MOD;
  }
  cout<<ans<<endl;
}