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
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18;

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll x,y,a,b,c; cin>>x>>y>>a>>b>>c;
  vll p(a), q(b), r(c);
  rep(i,a) cin>>p[i];
  rep(i,b) cin>>q[i];
  rep(i,c) cin>>r[i];
  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());
  sort(r.rbegin(),r.rend());
  
  ll ans=0;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  rep(i,x){
    ans+=p[i];
    que.push(p[i]);
  }
  rep(i,y){
    ans+=q[i];
    que.push(q[i]);
  }
  rep(i,c){
    if(que.empty()) break;
    ll now=que.top(); que.pop();
    if(now<r[i]){
      ans-=now;
      ans+=r[i];
    }
  }
  cout<<ans<<endl;
}