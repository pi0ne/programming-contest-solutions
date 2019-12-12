#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(ll i=(ll)(0); i<(ll)(n); ++i)
#define irep(i,m,n) for(ll i=(ll)(m); i<(ll)(n); ++i)
#define vi vector<int>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const long long MOD = 1e9 + 7;

signed main()
{
  int n;
  cin>>n;
  vi t(n+1), x(n+1), y(n+1);
  irep(i,1,n+1) cin>>t[i]>>x[i]>>y[i];
  t[0]=x[0]=y[0]=0;
  
  
  rep(i,n){
    int T=t[i+1]-t[i];
    int X=abs(x[i+1]-x[i]);
    int Y=abs(y[i+1]-y[i]);
    if(T<X+Y||(X+Y)%2!=T%2){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}