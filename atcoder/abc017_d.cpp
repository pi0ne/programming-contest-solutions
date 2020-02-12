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

const int maxn = 100005;
int dp[maxn]; // dp[i]:=i個目までの区切り方の場合数
int sum[maxn]; // sum[i]:=dp[i-1]までの累積和 ( sum[i+1]=dp[0]+dp[1]+ ... +dp[i] )

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int n,m; cin>>n>>m;
  vector<int> f(n);
  rep(i,n) cin>>f[i];

  vector<int> cnt(m+1, 0); // 現在見ている区間における数値iの個数
  vector<int> L(n+1, 0); // i:right, L[i]:left ... 各iにおけるダブらない区間を保存する
  int left = 0;
  rep(right, n){
    cnt[f[right]]++;
    while(left<right && cnt[f[right]]>1){
      cnt[f[left]]--;
      left++;
    }
    L[right+1]=left;
  }
  
  dp[0]=1;
  sum[0]=0; sum[1]=1; // sum[1]=dp[0] ∴ 1
  reps(i,n){
    dp[i]=(sum[i]-sum[L[i]]+MOD)%MOD; // +MODとするのは、sum[i+1]に格納される値がMODであるため
    sum[i+1]=(sum[i]+dp[i])%MOD;
  }
  
  cout<<dp[n]<<endl;
}