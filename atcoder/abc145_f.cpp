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

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// 色を塗る回数は左隣が空白であるブロックの個数となる
// kを考えなければ、その回数は、Σ(0, h[i+1]-h[i])
// 色を塗る回数を最小にする操作は左隣と同じ高さにすることであるから、k個高さを変えるのは、k個の列を削除するのと同義
// あとはどのn-k本の列について考えるかをdpで数え上げる

ll dp[305][305];
// dp:=i個目まで見て&i個目を残こし、j個残すときのmin
// j...n-k個まで見る

signed main()
{
  int n,k; cin>>n>>k;
  int m=n-k;
  vi h(n);
  rep(i,n) cin>>h[i];
  h.insert(h.begin(),0);
  rep(i,n+1) rep(j,m+1) dp[i][j]=LINF;
  dp[0][0]=0;
  for(int i=1; i<=n; i++) rep(j,m){
    ll now=LINF;
    rep(k,i){
      chmin(now,dp[k][j]+max(0,h[i]-h[k]));
    }
    dp[i][j+1]=now;
  }
  ll ans=LINF;
  rep(i,n+1) chmin(ans, dp[i][m]);
  cout<<ans<<endl;
}
