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

int n;
int t[100000];
int a[100000];
int b[100000];

bool isOK(int x);

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  cin>>n;
  rep(i,n){
    cin>>t[i]>>a[i]>>b[i];
    t[i]--;
  }
  
  int ok=-1e9-1, ng=1e9+1;
  while(abs(ok-ng)>1){
    int mid=(ok+ng)/2;
    if(isOK(mid)) ok=mid;
    else ng=mid;
  }
  cout<<ok<<endl;
}

bool isOK(int x){
  vector<int> l2r[100000];
  rep(i,n){
    if(a[i]<x) return false;
    int span=(a[i]-x)/b[i];
    int lb=max(0,t[i]-span);
    int rb=min(n-1,t[i]+span);
    l2r[lb].push_back(rb);
  }
  
  priority_queue<int, vi, greater<int>> R;
  rep(i,n){
    for(int r: l2r[i]) R.push(r);
    if(R.size()==0) return false; // 途中で途切れたらNG（i日目に食べて良い果物がない）
    int r=R.top(); R.pop();
    if(r<i) return false; // i番目の果物はi日目以降に食べなければならない
  }
  return true;
}
