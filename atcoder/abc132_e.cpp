#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }
int LCM(int a, int b) { return a * b / GCD(a, b); }

signed main()
{
  int n,k;
  cin>>n>>k;
  int ma=(n-1)*(n-2)/2;
  if(ma<k){
    cout<<-1<<endl;
    return 0;
  }
  int diff=ma-k;
  int rem=0;
  cout<<n-1+diff<<endl;
  reps(i,(n-1+diff)){
    if(i>2*(n-1)){
      rem=n-1+diff-2*(n-1);
      break;
    }
    else if(i>(n-1)) {
      if(i==2*(n-1)) cout<<i-(n-1)<<" "<<1<<endl;
      else cout<<i-(n-1)<<" "<<1+i-(n-1)<<endl;
    }
    else cout<<n<<" "<<i<<endl;
  }
  int dist=2;
  reps(i,rem){
    if(i!=1) if((i-1)%(n-1)==0) dist++;
    int p=i%(n-1);
    if(p==0)p=(n-1);
    int c=(p+dist)%(n-1);
    if(c==0)c=(n-1);
    cout<<p<<" "<<c<<endl;
  }
}

