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

int dp[205];
int cost[205];
bool visited[205];

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int n; cin>>n;
  int a,b; cin>>a>>b; a--,b--;
  int m; cin>>m;
  vector<vi> G(n);
  rep(i,m){
    int x,y; cin>>x>>y;
    x--,y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  memset(cost, -1, sizeof(cost));
  cost[a]=0;
  dp[a]=1;
  queue<int> q;
  q.emplace(a);
  while(!q.empty()){
    int v=q.front(); q.pop();
    if(visited[v]) continue;
    visited[v]=true;
    for(auto nv: G[v]){
      if(cost[nv]==-1 || cost[nv]>=cost[v]+1){
        (dp[nv]+=dp[v])%=MOD;
        cost[nv]=cost[v]+1;
      }
      q.emplace(nv);
    }
  }
  
  cout<<dp[b]<<endl;
}