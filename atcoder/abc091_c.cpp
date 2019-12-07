#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
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

inline bool inside(int y, int x, int H, int W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

signed main()
{
  int n; cin>>n;
  vector<pii> r(n);
  vector<pii> b(n);
  rep(i,n){
    int a,b; cin>>a>>b;
    r[i]=pii(a,b);
  }
  rep(i,n){
    int c,d; cin>>c>>d;
    b[i]=pii(c,d);
  }
  sort(r.rbegin(),r.rend());
  sort(b.rbegin(),b.rend());
  
  int ans=0;
  int bi=0;
  priority_queue<int, vi, greater<int>> q;
  rep(i,n){
    while(bi<n && r[i].first<b[bi].first){
      q.push(b[bi].second);
      bi++;
    }
    vi tmp;
    while(!q.empty()){
      int by=q.top(); q.pop();
      if(r[i].second<by) {
        ans++;
        break;
      }
      else tmp.push_back(by);
    }
    for(auto e: tmp){
      q.push(e);
    }
  }
  cout<<ans<<endl;
}
