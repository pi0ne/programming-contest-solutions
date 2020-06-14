#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
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
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

ll maxn=200100;

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll n,Q; cin>>n>>Q;
  vector<priority_queue<ll>> v(maxn);
  vll r(n);
  vll C(n);
  rep(i,n){
    ll a,b; cin>>a>>b;
    b--;
    v[b].emplace(a);
    r[i]=a;
    C[i]=b;
  }
  
  vpll cd(Q);
  rep(i,Q){
    ll c,d; cin>>c>>d; c--,d--;
    cd[i]={c,d}; 
  }
  
  priority_queue<ll, vector<ll>, greater<ll>> q;
  rep(i,maxn) if(!v[i].empty()){
    q.emplace(v[i].top());
  }
  
  vector<map<ll,ll>> w(maxn); // 最大ではないが、その園から転園済みのレートを管理
  map<ll,ll> m; // 各園の最大値を管理するqueueから転園済みのレートを管理
  rep(i,Q){
    ll c,to; tie(c,to)=cd[i];
    ll from=C[c];
    
    // 移動元の調整
    if(v[from].top()==r[c]){
      if(q.top()==r[c]){
        q.pop();
        while(!q.empty() && m[q.top()]){
          m[q.top()]--;
          q.pop();
        }
      }
      else m[r[c]]++;
    
      v[from].pop();
      while(!v[from].empty() && w[from][v[from].top()]){
         w[from][v[from].top()]--;
         v[from].pop();
      }
      if(!v[from].empty()){
        q.emplace(v[from].top());
      }
    }else{
      w[from][r[c]]++;
    }
    
    // 移動先の調整
    if(v[to].empty()){
      q.emplace(r[c]);
    }else if(v[to].top()<r[c]){
      if(q.top()==v[to].top()){
        q.pop();
        while(!q.empty() && m[q.top()]){
          m[q.top()]--;
          q.pop();
        }
        q.emplace(r[c]);
      }else{
        m[v[to].top()]++;
        q.emplace(r[c]);
      }
    }
    v[to].emplace(r[c]);
    
    C[c]=to;
    
    cout<<q.top()<<endl;
  }
}