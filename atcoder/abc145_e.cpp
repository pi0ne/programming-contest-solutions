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

// 参考: https://atcoder.jp/contests/abc145/submissions/8470228
// t-1分時点で、食べる時間が長いものを選ぶと得である、ということに着目する
// 美味しさが最大である選び方が求まったとき、t-1秒時点に最大時間のものを配置すると考えると、
// これをt-1より前に配置することで、美味しさが大きくなることはない
// よって、美味しさが最大となる選び方は、末尾t-1に最大時間のものを配置する場合を考えれば良い
// そのため、各料理についてAで昇順にソートし、dp[i][j]:=i種類まででj分で得られるポイントの最大値 として求める
// dp[i-1][j]の最大値と、i番目の美味しさの和を求め、これの最大値が求める解である

int dp[3005][3005];

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int n,t; cin>>n>>t;
  vector<pii> ab(n);
  rep(i,n) cin>>ab[i].first>>ab[i].second;
  vsort(ab);
  int ans=0;
  rep(i,n){
    rep(j,t){
      // i+1にi種類までで各時間で得られるポイントの最大値を格納している
      if(j+ab[i].first<t) chmax(dp[i+1][j+ab[i].first],dp[i][j]+ab[i].second);
      // ↑(j分からiを食べてt-1分以内なら)i-1種類からj分で得られるポイント + iを食べることで得られるポイント
      // ↓i-1種類からj分で得られる最大値
      chmax(dp[i+1][j],dp[i][j]);
      
      // i-1種類でt-1分までに完食できるポイント + t-1分にiを食べることで得られるポイント
      // こう書けばdpテーブルを隅々まで埋める必要はない
      chmax(ans,dp[i][j]+ab[i].second);
    }
  }
  cout<<ans<<endl;
  return 0;
}
