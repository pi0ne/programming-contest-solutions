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

int N;
int cnt[101];
ll dp[101]; // dp[i] := 約数の個数がi個になるような素因数の組合わせ方の数

void prime_factorize(){
  for(int i=2;i<=N;i++){
    int x=i;
    for(int j=2;x>1;j++){
      while(x%j==0){
        cnt[j]++;
        x/=j;
      }
    }
  }
}

signed main()
{
  cin>>N;
  prime_factorize();
  
  dp[1]=1;
  for(int i=1;i<=N;i++) if(cnt[i]){ // i: iが約数として存在するか
    for(int j=75;j>=1;j--){         // j: 約数の個数
      for(int x=1;x<=cnt[i];x++){   // x: n!の中にある約数iの数(指数)
        if(j*(x+1)<=75) dp[j*(x+1)]+=dp[j];
      }
    }
  }

  cout<<dp[75]<<endl;
}
