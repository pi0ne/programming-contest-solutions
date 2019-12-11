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
  vector<vi> a(2, vi(n+1));
  
  rep(i,2) rep(j,n) cin>>a[i][j+1];
  
  vector<vi> s(2, vi(n+1));
  a[0][0]=0;
  s[0][0]=0;
  rep(i,2) rep(j,n){
    s[i][j+1]=s[i][j]+a[i][j+1];
  }
  
  int ans=0;
  rep(i,n){
    chmax(ans,s[0][i+1]+s[1][n]-s[1][i]);
  }
  cout<<ans<<endl;
}