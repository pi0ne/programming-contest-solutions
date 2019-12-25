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
#define replace_all(s, b, A) replace(s.begin(),s.end(), b, A);
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

template<class T> inline bool chmax(T& A, T b) { if (A < b) { A = b; return 1; } return 0; }
template<class T> inline bool chmin(T& A, T b) { if (A > b) { A = b; return 1; } return 0; }

ll GCD(ll A, ll b) { return b ? GCD(b, A%b) : A; }
ll LCM(ll A, ll b) { return A / GCD(A, b)* b; }

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
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int h,w,n; cin>>h>>w>>n;
  vi A(n);
  rep(i,n) {
    cin>>A[i]; A[i];
  }
  
  int k=0,cnt=A[0];
  rep(i,h){
    if(i%2==0) rep(j,w){
      if(cnt==0){
        cnt=A[++k];
      }
      cnt--;
      cout<<k+1;
      if(j!=w-1) cout<<" ";
    }
    
    if(i%2==1){
      deque<int> q;
      for(int j=w-1; j>=0; j--){
        if(cnt==0){
          cnt=A[++k];
        }
        cnt--;
        q.push_front(k);
      }
      rep(j,w){
        cout<<(q.front()+1);
        q.pop_front();
        if(j!=w-1) cout<<" ";
      }
    }
    cout<<endl;
  }
}
