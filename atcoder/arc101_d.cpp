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
#define cout(d) cout << d << endl;
#define coutd(d) cout << std::setprecision(10) << d << endl;
#define cinline(n) getline(cin, n);
#define replace_all(s, b, a) replace(s.begin(), s.end(), b, a);
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

template <class T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return 1;
  }
  return 0;
}

ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }

const int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(int y, int x, int H, int W)
{
  return (y >= 0 && x >= 0 && y < H && x < W);
}

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

// 参考
// https://betrue12.hateblo.jp/entry/2018/08/26/122740
// http://hos.ac/slides/20140319_bit.pdf

struct BIT
{
  long long n;
  vector<long long> dat;

  void initialize(long long n_input) {
    n = n_input + 1;
    dat.resize(n + 1);
    for (int i = 0; i <= n; i++) dat[i] = 0;
  }

  long long sum(long long i) {
    long long s = 0;
    while (i >= 0) {
      s += dat[i];
      i = (i & (i + 1)) - 1;
    }
    return s;
  }

  long long sum_between(long long i, long long j) {
    return i <= j ? sum(j) - sum(i - 1) : 0;
  }

  void add(long long i, long long x) {
    while (i <= n) {
      dat[i] += x;
      i |= i + 1;
    }
  }
};

signed main()
{
  ll n;
  cin >> n;
  vi a(n), as(n);
  rep(i, n) {
    cin >> a[i];
    as[i] = a[i];
  }
  vsort(as);

  int ub = n; // ng ... 「基準値以上の値が半数以上あるか」という判定で中央値を求めるため下限がok
  int lb = 0; // ok
  BIT bit;

  ll border = ((n * (n + 1) / 2) + 1) / 2;
  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    int midn = as[mid];        // asc sort された a の要素値で、中央値になりうるかを判定する
    bit.initialize(2 * n + 1); // 2n とするのは index となる累積和の値が負数になりうるため(オフセット)
    int sum = 0;               // 累積和
    bit.add(sum+n, 1);         // as の1個目の要素が midn 以上だった場合、 result+=1 されるよう
                               // 「累積和が0の境界が1」を初期状態としている
    ll result = 0;             // midn が中央値となりうる区間の総数
    rep(i, n) {
      sum += a[i] >= midn ? 1 : -1;
      result += bit.sum(sum + n); // この時点の累積和より小さい累積和である境界の数が求める区間数と一致する
      bit.add(sum + n, 1);
    }
    if (result >= border)
      lb = mid;
    else
      ub = mid;
  }
  cout << as[lb] << endl;
}