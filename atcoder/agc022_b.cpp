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

// 参考: http://kurkur.hatenablog.com/entry/2018/04/01/050530

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int n; cin>>n;
  
  if(n==3){
    cout<<"2 5 63"<<endl;
    return 0;
  }
  if(n==4){
    cout<<"2 5 20 63"<<endl;
    return 0;
  }
  
  int a,b;
  if(n%2==1){
    a=min((n/4-1)*4+3,9999);
    b=n-a;
  }else{
    a=min((n-1)/4*4,10000);
    b=n-a;
  }
  reps(i,a) cout<<3*i<<" ";
  int cnt=0, x=2;
  while(true){
    if(x%3==0){
      x+=2;
      continue;
    }else{
      cout<<x<<((cnt!=b-1) ? " ":"\n");
      if(cnt==b-1) break;
      else cnt++;
      x+=2;
    }
  }
}