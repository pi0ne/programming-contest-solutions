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
  ll t; cin>>t;
  rep(ki,t){
    ll n; cin>>n;
    vector<tuple<ll,ll,ll>> v(n);
    vector<tuple<ll,ll,ll>> sv(n);
    
    rep(i,n){
      ll s,e; cin>>s>>e;
      v[i]={s,e,i};
      sv[i]={s,e,i};
    }
    
    sort(all(sv));
    
    ll fs,fe,fi; tie(fs,fe,fi)=sv[0];
    ll lj=fs, rj=fe;
    ll ss,se,si; tie(ss,se,si)=sv[1];
    ll lc=ss,rc=se;
    map<tuple<ll,ll,ll>,char> m;
    m[sv[0]]='J';
    m[sv[1]]='C';
    bool ok=true;
    irep(i,2,n){
      ll s,e,z; tie(s,e,z)=sv[i];
      ll nl=s, nr=e;
      if(rj<=nl || nr<=lj){
        m[sv[i]]='J';
        lj=nl, rj=nr;
      }else if(rc<=nl || nr<=lc){
        m[sv[i]]='C';
        lc=nl, rc=nr;
      }else{
        ok=false;
        break;
      }
    }
    if(ok){
      string ans="";
      rep(i,n){
        ans+=m[v[i]];
      }
      cout<<"Case #"<<ki+1<<": "<<ans<<endl;
    }else{
      cout<<"Case #"<<ki+1<<": IMPOSSIBLE"<<endl;
    }
    
  }
}