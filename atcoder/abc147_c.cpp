#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int a[20];
int x[20][20];
int y[20][20];

int counter(int x){
  if(x==0) return 0;
  return counter(x>>1)+(x&1);
}

signed main()
{
  int n;
  cin>>n;
  
  for(int i=1; i<=n; i++){
    cin>>a[i];
    for(int j=1; j<=a[i]; j++){
      cin>>x[i][j]>>y[i][j];
    }
  }
  int ans=0;
  // bits ビットが立っているところが人iが正しい証言をしていることを意味する
  for(int bits=1; bits<(1<<n); bits++){
    bool ok=true;
    // 最大15人の人iについてのループ
    for(int i=1; i<=n; i++){
      // ビットiが立っている時だけ処理する
      // 正しい証言をしていると仮定しているもの(=ビットが立っている)だけ確認すればよい
      // iが立っていないものは「不確か」であって、「不正確であること」では無い事に注意
      if(!(bits & (1<<(i-1)))) continue;
      // 各人iの証言についてのループ
      for(int j=1; j<=a[i]; j++){
        // 矛盾しないかを判定する
        // 0^1 (bits上は不親切と仮定したのに正直者であると証言してしまっている)
        // 1^0 (正直者と仮定したのに不親切と証言してしまっている)
        if(((bits>>x[i][j]-1)&1) ^ y[i][j]) {
          // bits上正しいと仮定した人iの証言が全て矛盾しなければここを通らず、
          // bitsの立っているビットの数が、正直者の数と同値になる
          ok = false;
          break;
        }
      }
    }
    if(ok) chmax(ans, counter(bits));
  }
  cout<<ans<<endl;
}