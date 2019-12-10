#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i,n) for(ll i=(ll)(0); i<(ll)(n); ++i)
#define vi vector<int>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const long long MOD = 1e9 + 7;

ll m,a,r,c,h;
string s;

signed main()
{
  ll n; cin>>n;
  
  rep(i,n){
    cin>>s;
    if(s[0]=='M')m++;
    if(s[0]=='A')a++;
    if(s[0]=='R')r++;
    if(s[0]=='C')c++;
    if(s[0]=='H')h++;
  }
  
  ll d[]={m,a,r,c,h};
  
  int x[]={0,0,0,0,0,0,1,1,1,2};
  int y[]={1,1,1,2,2,3,2,2,3,3};
  int z[]={2,3,4,3,4,4,3,4,4,4};
  ll ans=0;
  rep(i,10){
    ans+=d[x[i]]*d[y[i]]*d[z[i]];
  }
  cout<<ans<<endl;
}