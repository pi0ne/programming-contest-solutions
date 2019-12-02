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

// 参考: http://drken1215.hatenablog.com/entry/2019/05/15/002400

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n,k;
  cin>>n>>k;
  vector<vll> s(n);
  rep(i,n){
    ll t,d; cin>>t>>d; --t;
    s[t].push_back(d);
  }
  for(auto &v: s){
    sort(v.begin(), v.end(), greater<ll>());
    if(v.empty()) v.push_back(-LINF);
  }
  // 配列の最大値が大きい順にソート
  sort(s.begin(), s.end(), [&](vector<ll> a, vector<ll> b){ return a[0] > b[0];});
  
  // k種類選ぶ
  ll now = 0;
  priority_queue<ll> que;
  rep(i,k){
    now += s[i][0];
    for(int j=1; j<s[i].size(); j++) que.push(s[i][j]);
  }
  // k番目以降のネタの配列の要素もqueに入れる
  for(int i=k; i<n; ++i) rep(j, s[i].size()) que.push(s[i][j]);
  
  ll ans = now + k*k;
  for(ll x = k-1; x >= 1; --x){
    ll v=s[x][0];
    ll w=que.top();
    if(v<w){
      que.pop();
      now+=w;
      que.push(v);
      now-=v;
    }
    ans = max(ans, now + x*x);
  }
  cout<<ans<<endl;
}
