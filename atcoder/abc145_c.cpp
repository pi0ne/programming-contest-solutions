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
 
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }
 
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
 
signed main()
{
  int n;cin>>n;
  vector<pii> xy(n);
  rep(i,n){
    cin>>xy[i].first>>xy[i].second;
  }
  vsort(xy);
  double ans=0;
  do {
    int prex=INF;
    int prey=INF;
    rep(i,n){
      if(prex==INF){
        prex=xy[i].first;
        prey=xy[i].second;
        continue;
      }
      ans+=sqrt((double)(prex-xy[i].first)*(prex-xy[i].first)+(prey-xy[i].second)*(prey-xy[i].second));
    }
  } while (next_permutation(xy.begin(), xy.end()));
  double tmp=1;
  reps(i,n){
    tmp*=i;
  }
  ans/=tmp;
  coutd(ans);
}