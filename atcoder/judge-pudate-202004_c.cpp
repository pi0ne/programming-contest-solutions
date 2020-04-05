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

ll a1,a2,a3;
ll ans=0;

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>a1>>a2>>a3;
  vll a(a1+a2+a3);
  iota(all(a),1);
  do{
    vvll x(3, vll(3,INF));
    rep(i,a1) x[0][i]=a[i];
    rep(i,a2) x[1][i]=a[i+a1];
    rep(i,a3) x[2][i]=a[i+a1+a2];
    
    bool ok=true;
    rep(i,3){
      rep(j,2){
        if(x[i][j]!=INF && x[i][j]>=x[i][j+1]) ok=false;
        if(x[j][i]!=INF && x[j][i]>=x[j+1][i]) ok=false;
      }
    }
    if(ok) ans++;
    
  }while(next_permutation(all(a)));
  cout<<ans<<endl;
}