#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (ll i = (ll)(0); i < (ll)(n); ++i)
#define reps(i, n) for (ll i = (ll)(1); i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = ((ll)(n)-1); i >= 0; i--)
#define rreps(i, n) for (ll i = ((ll)(n)); i > 0; i--)
#define irep(i, m, n) for (ll i = (ll)(m); i < (ll)(n); ++i)
#define ireps(i, m, n) for (ll i = (ll)(m); i <= (ll)(n); ++i)
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
#define sz(x) ll(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n,m,l; cin>>n>>m>>l;
  ll G[n][n];
  rep(i,n){
    rep(j,n) G[i][j]=INF;
    G[i][i]=0;
  }
  
  rep(i,m){
    ll a,b,c; cin>>a>>b>>c;
    a--,b--;
    G[a][b]=G[b][a]=c;
  }
  
  ll q; cin>>q;
  vector<pll> Q;
  rep(i,q){
    ll s,t; cin>>s>>t;
    s--,t--;
    Q.emplace_back(s,t);
  } 
  
  vector<vector<pll>> dist(n,vector<pll>(n,{INF,INF}));
  rep(i,n){
    dist[i][i]={0,0};
    priority_queue<pair<pll,ll>, vector<pair<pll,ll>>, greater<pair<pll,ll>>> q;
    q.push({{0,0},i});
    while(!q.empty()){
      auto p=q.top(); q.pop();
      ll v=p.second;
      ll cnt=p.first.first;
      ll used=p.first.second;
      if(dist[i][v]<p.first) continue;
      for(ll nv=0; nv<n; nv++){
        if(nv==v) continue;
        if(G[v][nv]>l) continue;
        ll nused=used+G[v][nv];
        pll np;
        if(nused>l){
          np={cnt+1,G[v][nv]};
        }else{
          np={cnt,nused};
        }
        if(chmin(dist[i][nv],np)){
          q.emplace(np,nv);
        }
      }
    }
  }
  
  rep(i,q){
    ll s=Q[i].first, t=Q[i].second;
    if(dist[s][t].first>=INF) cout<<-1<<endl;
    else cout<<dist[s][t].first<<endl;
  }
  
}