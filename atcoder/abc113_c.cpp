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

signed main()
{
  int n,m;
  cin>>n>>m;
  vector<priority_queue<pii, vector<pii>, greater<pii>>> v(n);
  for(int i=0;i<m;i++){
    int p,y; cin>>p>>y;
    p--;
    v[p].emplace(y,i);
  }
  vector<string> ans(m);
  for(int i=0;i<n;i++){
    
    string ppre="";
    if(99999<i+1) {}
    else if(9999 <i+1) ppre="0";
    else if(999  <i+1) ppre="00";
    else if(99   <i+1) ppre="000";
    else if(9    <i+1) ppre="0000";
    else ppre="00000";
    ppre += to_string(i+1);
    
    auto que = v[i];
    int cnt=1;
    while(!que.empty()){
      auto e = que.top();
      que.pop();
      string ypre="";
      if     (99999<cnt) {}
      else if(9999 <cnt) ypre="0";
      else if(999  <cnt) ypre="00";
      else if(99   <cnt) ypre="000";
      else if(9    <cnt) ypre="0000";
      else ypre="00000";
      string res = ppre+ypre+to_string(cnt);
      ans[e.second] = res;
      cnt++;
    }
  }
  rep(i,m){
    cout<<ans[i]<<endl;
  }
}
