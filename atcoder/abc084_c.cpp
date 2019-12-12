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
  vi c(n-1),s(n-1),f(n-1);
  rep(i,n-1){
    cin>>c[i]>>s[i]>>f[i];
  }
  rep(i,n){
    int t=0;
    irep(j,i,n-1){
      if(t<s[j]){
        t+=(s[j]-t)+c[j];
      }else{
        if(t%f[j]) t+=(f[j]-(t%f[j]))+c[j];
        else t+=c[j];
      }
    }
    cout<<t<<endl;
  }
}