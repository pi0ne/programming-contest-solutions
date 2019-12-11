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
  int c[3][3];
  rep(i,3) rep(j,3) cin>>c[i][j];
  rep(i,101){
    int b1=c[0][0]-i;
    int b2=c[0][1]-i;
    int b3=c[0][2]-i;
    bool ok=true;
    irep(j,1,3){
      if(!((c[j][0]-b1)==(c[j][1]-b2)&&(c[j][1]-b2)==(c[j][2]-b3))){
        ok=false;
      }
    }
    if(ok){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
}