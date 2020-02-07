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

class UnionFind{
  public:
  // 親の番号を格納する．親の場合は-(その集合のサイズ)
  vector<int> Parent; 
  
  // 全て-1
  UnionFind(int N){
    Parent = vector<int>(N, -1);
  }
  
  // Aがどのグループに属しているか
  int root(int A){
    if(Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]); // return前に自分の親を更新することで高速化
  }
  
  // 自分のいるグループの頂点数を調べる
  int size(int A){
    return -Parent[root(A)]; 
  }
  
  // AとBをくっつける
  bool connect(int A, int B){
    // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
    A = root(A);
    B = root(B);
    if(A == B){
      // すでにくっついているからくっつけない
      return false;
    }
    
    // グループのサイズが大きい方(A)に小さい方(B)をくっつけたい
    // 大小が逆ならひっくり返す
    if(size(A) < size(B)) swap(A, B);
    
    // Aのサイズを更新する
    Parent[A] += Parent[B];
    // Bの親をAに変更する
    Parent[B] = A;
    
    return true;
  }
};

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  int n,m; cin>>n>>m;
  vi a(m), b(m);
  rep(i,m){
    cin>>a[i]>>b[i];
    a[i]--; b[i]--;
  }
  auto uf = UnionFind(n);
  vector<ll> ans(m);
  ans[m-1]=1LL*n*(n-1)/2;
  for(int i=m-2; i>=0; i--){
    if(uf.root(a[i+1])==uf.root(b[i+1])){
      ans[i]=ans[i+1];
      continue;
    }
    ans[i]=ans[i+1]-(1LL*uf.size(a[i+1])*uf.size(b[i+1]));
    uf.connect(a[i+1],b[i+1]);
  }
  rep(i,m) cout<<ans[i]<<endl;
}