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
  int n,y; cin>>n>>y;
  int i=0;
  while(i*10000<=y){
    int j=0;
    while((i*10000+j*5000)<=y){
      if((y-(i*10000+j*5000))/1000==(n-i-j)){
        cout<<i<<" "<<j<<" "<<(y-(i*10000+j*5000))/1000<<endl;
        return 0;
      }
      j++;
    }
    i++;
  }
  cout<<-1<<" "<<-1<<" "<<-1<<endl;
}