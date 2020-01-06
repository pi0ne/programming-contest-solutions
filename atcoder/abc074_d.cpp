#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define ll long long

int d[305][305];
int flgs[305][305];

int main(){
    int n; cin>>n;
    rep(i,n) rep(j,n) cin>>d[i][j];

    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(d[i][j]>d[i][k]+d[k][j]){
                    cout<<-1<<endl;
                    return 0;
                }
                if(d[i][j]==d[i][k]+d[k][j] && d[i][k] && d[k][j]) flgs[i][j]=true;
            }
        }
    }
    ll ans=0;
    rep(i,n) for(int j=i+1;j<n;j++){
        if(!flgs[i][j]) ans+=d[i][j];
    }
    cout<<ans<<endl;
}