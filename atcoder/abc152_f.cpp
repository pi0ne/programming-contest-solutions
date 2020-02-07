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
#define int long long
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

const ll MOD = 1e18;

long long mod_pow(long long x, long long n){
	if(n == 0) return 1;
	long long res = mod_pow(x*x % MOD, n / 2);
	if(n & 1) res = res*x % MOD;
	return res;
}

int n;
vector<pii> G[50];
vector<pii> pre;
 
void dfs(int u, int p){
	for(auto i : G[u]){
		if(i.first == p) continue;
		pre[i.first] = {u, i.second};
		dfs(i.first, u);
	}
}

// 参考
// https://atcoder.jp/contests/abc152/submissions/9617510

signed main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back({b, i});
		G[b].push_back({a, i});
	}
	int m;
	cin >> m;
	vector<int> u(m), v(m);
	rep(i, m){
		cin >> u[i] >> v[i];
		u[i]--; v[i]--;
	}
	vector<vector<bool> > use(m, vector<bool>(n - 1, false));
	rep(i, m){
		pre.clear();
		pre.resize(n, {-1, -1});
		dfs(u[i], -1);
		int now = v[i];
		// cout << v[i] << ' ';
		while(now != -1){
			if(pre[now].second == -1) break;
			use[i][pre[now].second] = true;
			now = pre[now].first;
			// cout << now << ' ';
		}
		// cout << endl;
	}
	int ans = mod_pow(2, n - 1);
	for(int i = 1; i < (1 << m); i++){
		vector<bool> tmp(n - 1, false);
		int cnt = __builtin_popcountll(i);
		rep(j, m){
			if(i & (1 << j)){
				rep(k, n - 1){
					tmp[k] = tmp[k] | use[j][k];
				}
			}
		}
		int sum = 0;
		// cout << i << " : ";
		rep(j, n - 1){
			if(tmp[j]){
				sum++;
				// cout << j << ' ';
			}
		}
		// cout << endl;
		int now = mod_pow(2, n - 1 - sum);
		if(cnt % 2) ans = (ans + MOD - now) % MOD;
		else ans = (ans + now) % MOD;
	}
	cout << ans << endl;
}