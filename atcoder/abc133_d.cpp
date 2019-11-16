#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }

const int INF = 1e9;
const ll MOD = 1e9+7;

ll dfs(vector<vi> &G, int k, int v, int p){
  int can_use_color;
  if(p==-1) can_use_color=k-1;
  else can_use_color=k-2;
  
  ll res=1;
  for(auto u: G[v]){
    if(u==p) continue;
    res*=(ll)can_use_color;
    res%=MOD;
    can_use_color--;
  }
  for(auto u: G[v]){
    if(u==p) continue;
    res*=dfs(G,k,u,v);
    res%=MOD;
  }
  return res;
}

signed main()
{
  int n,k;
  cin>>n>>k;
  vector<vi> G(n);
  rep(i,n-1){
    int a,b;cin>>a>>b; a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll ans=k*dfs(G,k,0,-1);
  ans%=MOD;
  cout<<ans<<endl;
}

