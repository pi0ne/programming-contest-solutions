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

ll h,w,k;
char G[15][1005];

ll counter(ll x){
  if(x==0) return 0;
  return counter(x>>1)+(x&1);
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>h>>w>>k;
  rep(i,h){
    rep(j,w){
      cin>>G[i][j];
    }
  }
  
  ll ans=INF;
  for(ll bit=0; bit<(1<<(h-1)); bit++){
    ll yoko=counter(bit);
    vll borders;
    rep(i,h-1){
      if(bit&(1<<i)){
        borders.push_back(i+1);
      }
    }
    borders.push_back(h);
    vll cntByBlock(borders.size());
    ll tate=0;
    
    bool ok=true;
    rep(i,w){
      rep(j,borders.size()){
        ll start=0;
        if(j>0) start=borders[j-1];
        
        ll cnt=0;
        irep(ki,start,borders[j]){
          if(G[ki][i]=='1'){
            cnt++;
          }
        }
        if(cnt>k){
          ok=false;
          break;
        }else{
          if(cntByBlock[j]+cnt>k){
            tate++;
            rep(kj,cntByBlock.size()) cntByBlock[kj]=0;
            i--;
            break;
          }else{
            cntByBlock[j]+=cnt;
          }
        }
      }
      if(!ok) break;
    }
    
    if(ok) chmin(ans,yoko+tate);
  }
  
  cout<<ans<<endl;
}