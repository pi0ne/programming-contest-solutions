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

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

const int maxk=20000;
bool dp[100][100][maxk+1]; // dp[i][j][k]:=(i,j)の偏りをkにできるか
int h,w;
int a[100][100];
int b[100][100];

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  cin>>h>>w;
  rep(i,h) rep(j,w) cin>>a[i][j];
  rep(i,h) rep(j,w) cin>>b[i][j];
  
  dp[0][0][0]=true;
  
  rep(i,h) rep(j,w){
    
    int d = abs(a[i][j]-b[i][j]);
    
    ireps(ki,0,maxk){
      if(dp[i][j][ki]){
        int e=abs(ki-d);
        dp[i+1][j][e]=true;
        dp[i][j+1][e]=true;
        dp[i+1][j][ki+d]=true;
        dp[i][j+1][ki+d]=true;
      }
    }
  }
  
  int ans=INF;
  for(int i=0; i<=maxk; i++){
    if(dp[h][w-1][i]){
      ans=i;
      break;
    }
    if(dp[h-1][w][i]){
      ans=i;
      break;
    }
  }
  cout<<ans<<endl;
}
