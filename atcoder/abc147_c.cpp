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

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int a[20];
int x[20][20];
int y[20][20];

int counter(int x){
  if(x==0) return 0;
  return counter(x>>1)+(x&1);
}

signed main()
{
  int n;
  cin>>n;
  
  for(int i=1; i<=n; i++){
    cin>>a[i];
    for(int j=1; j<=a[i]; j++){
      cin>>x[i][j]>>y[i][j];
    }
  }
  int ans=0;
  for(int bits=1; bits<(1<<n); bits++){
    bool ok=true;
    for(int i=1; i<=n; i++){
      if(!(bits & (1<<(i-1)))) continue;
      for(int j=1; j<=a[i]; j++){
        if(((bits>>x[i][j]-1)&1) ^ y[i][j]) ok = false;
      }
    }
    if(ok) chmax(ans, counter(bits));
  }
  cout<<ans<<endl;
}