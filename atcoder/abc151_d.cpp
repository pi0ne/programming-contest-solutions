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
 
int h,w;
vector<string> g(25);
 
int bfs(int y, int x){
  int cost[25][25];
  rep(i,h) rep(j,w) cost[i][j]=INF;
  cost[y][x]=0;
  queue<pii> q;
  q.push(pii(y,x));
  int res=0;
  while(!q.empty()){
    pii now=q.front();
    q.pop();
    rep(i,4){
      int ny=now.first+dy[i];
      int nx=now.second+dx[i];
      if(inside(ny,nx,h,w) && g[ny][nx]=='.'
          && cost[ny][nx] >= cost[now.first][now.second]
          && cost[ny][nx] > cost[now.first][now.second]+1){
        q.push(pii(ny,nx));
        cost[ny][nx]=cost[now.first][now.second]+1;
        chmax(res,cost[ny][nx]);
      }
    }
  }
  return res;
}
 
signed main()
{
  cin>>h>>w;
  rep(i,h) cin>>g[i];
  
  int ans=0;
  rep(i,h){
    rep(j,w){
      if(g[i][j]=='#')continue;
      chmax(ans,bfs(i,j));
    }
  }
  cout<<ans<<endl;
}