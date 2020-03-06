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
#define pqasc priority_queue<long long, vector<long long>, greater<long long>>
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ul = unsigned long;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
class UnionFind{
private:
  vector<int> Parent; 
 public:
  UnionFind(int N){
    Parent = vector<int>(N, -1);
  }
  
  int root(int A){
    if(Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }
  
  int size(int A){
    return -Parent[root(A)]; 
  }
  
  bool connect(int A, int B){
    A = root(A);
    B = root(B);
    if(A == B){
      return false;
    }
    if(size(A) < size(B)) swap(A, B);
    Parent[A] += Parent[B];
    Parent[B] = A;
    return true;
  }
  
  bool isSame(int A, int B){
    return root(A) == root(B);
  }
};
 
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
 
int dp[100005][13]; // dp[i][j]:=上からi桁目までの数で余りがjとなるものの数
 
signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  string s; cin>>s;
  int n=s.size();
  dp[0][0]=1;
  rep(i,n){
    if(s[i]=='?'){
      rep(j,10){
        rep(k,13){
          int l=(k*10+j)%13;
          (dp[i+1][l]+=dp[i][k])%=MOD;
        }
      }
    }else{
      rep(j,13){
        int k=(j*10+(s[i]-'0'))%13;
        (dp[i+1][k]+=dp[i][j])%=MOD;
      }
    }
  }
  cout<<dp[n][5]<<endl;
}