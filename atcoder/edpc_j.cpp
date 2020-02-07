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
#define FILL(v, n, x) fill(v, v + n, x);dfm
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

// dp[i][j][k]:=残り1個の皿がi枚、2個の皿がj枚、3個の皿がk枚の時の期待値
// 全ての皿の枚数をn枚とすると、
// dp[i][j][k]=dp[i][j][k]*((n-i-j-k)/n) + dp[i-1][j][k]*(i/n) + dp[i+1][j-1][k]*(j/n) + dp[i][j+1][k-1]*(k/n) + 1
// ∴ dp[i][j][k]=(dp[i-1][j][k]*i + dp[i+1][j-1][k]*j + dp[i][j+1][k-1]*k + n)/(i+j+k)
double dp[305][305][305];
int n;

double rec(int i, int j, int k){
	if(dp[i][j][k]>=0) return dp[i][j][k];
	if(i==0&&j==0&&k==0) return 0.0;
	double res=0.0;
	if(i>0) res+=rec(i-1,j,k)*i;
	if(j>0) res+=rec(i+1,j-1,k)*j;
	if(k>0) res+=rec(i,j+1,k-1)*k;
	res+=n;
	res*=1.0/(i+j+k);
	return dp[i][j][k]=res;
}

int main(){
	cin>>n;
	int one=0, two=0, three=0;
	rep(i,n){
		int a; cin>>a;
		if(a==1){
			one++;
		}else if(a==2){
			two++;
		}else{
			three++;
		}
	}
	memset(dp,-1,sizeof(dp));
	coutd(rec(one,two,three))
}