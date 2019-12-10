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
#define FILL(v, n, x) fill(v, v + n, x);dfm
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

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// 参考: https://atcoder.jp/contests/abc147/submissions/8886712

ll n,x,d;

ll F(ll y){
  ll mx=(n-y+n-1)*y/2;
  ll mn=y*(y-1)/2;
  return mx-mn+1;
}

ll G(ll y){
  ll l1=((n-y)+(n-1))*y/2,
  l2=y*(y-1)/2,
  r1=((n-y-d)+(n-1))*(y+d)/2+x,
  r2=(y+d)*(y+d-1)/2+x;
  return max(min(l1,r1)-max(l2,r2)+1,0LL);
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  cin>>n>>x>>d;
  if(d==0){
    cout<<(x!=0 ? n+1 : 1)<<endl;
    return 0;
  }
  if(x==0) {
    cout<<(n*(n-1)/2+1)<<endl;
    return 0;
  }
  
  if(x<0) x*=-1,d*=-1;
  
  // x,dを互いに素にする
  int g=__gcd(x,d);
  x/=g;
  d/=g;
  
  ll ans=0;
  for(int i=0;i<=n;i++){
    ans+=F(i);
  }
  
  for(int i=0;i<=n;i++){
    if(0<=i+d&&i+d<=n) ans-=G(i);
  }
  
  cout<<ans<<endl;
}