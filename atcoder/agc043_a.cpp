#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

char G[105][105];
ll cost[105][105];

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll h,w; cin>>h>>w;
  rep(i,h) rep(j,w) cin>>G[i][j];
  
  queue<pll> q;
  q.emplace(0,0);
  memset(cost,-1,sizeof(cost));
  cost[0][0]=0;
  if(G[0][0]=='#') cost[0][0]=1;
  while(!q.empty()){
    ll y=q.front().first, x=q.front().second;
    q.pop();
    rep(i,2){
      ll ny=y+dy[i], nx=x+dx[i];
      if(inside(ny,nx,h,w)){
        if(G[y][x]=='#'){
          if(cost[ny][nx]==-1 || cost[ny][nx]>cost[y][x]){
            if(cost[ny][nx]==-1) q.emplace(ny,nx);
            cost[ny][nx]=cost[y][x];
          }
        }else{
          if(G[ny][nx]=='#'){
            if(cost[ny][nx]==-1 || cost[ny][nx]>cost[y][x]+1){
              if(cost[ny][nx]==-1) q.emplace(ny,nx);
              cost[ny][nx]=cost[y][x]+1;
            }
          }else{
            if(cost[ny][nx]==-1 || cost[ny][nx]>cost[y][x]){
              if(cost[ny][nx]==-1) q.emplace(ny,nx);
              cost[ny][nx]=cost[y][x];
            }
          }
        }
      }
    }
  }
  
  cout<<cost[h-1][w-1]<<endl;
}