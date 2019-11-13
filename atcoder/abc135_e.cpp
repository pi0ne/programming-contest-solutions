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

vector<pii> calc(int x, int y, int k){
  vector<pii> res;
  
  if(x+y==k){
    res.emplace_back(x,y);
    return res;
  }
  
  int n=(x+y+k-1)/k;      // 分子に分母-1(k-1)を加算することで、x+y/kの天井関数としている. ceil((x+y)/k)と同じ
  if(n<=1)n=2;
  if((x+y)%2!=n*k%2)n++;  // kと(x+y)のパリティが合わない場合(k:奇数、x+y:偶数)は、その調整のため1回多く移動が必要
  
  if(n==3&&x<k){
    // 特殊パターン
    res.emplace_back(x,x-k);
    int overRight=(k+x-y)/2;
    res.emplace_back(x+overRight,y-(k-overRight));
    res.emplace_back(x,y);
  }else{
    int over=(k*n-(x+y))/2;
    rep(i,n){
      int dist=(i+1)*k;
      if(dist<=y+over){
        res.emplace_back(0,dist);
      }else if(dist<=y+over+x){
        res.emplace_back(dist-(y+over),y+over);
      }else{
        res.emplace_back(x,y+(n-(i+1))*k);
      }
    }
  }
  return res;
}

signed main()
{
  int k,x,y;
  cin>>k>>x>>y;
  
  // x>=0, y>=0, x>=y である前提で計算し、最後に修正
  bool xflg=false;
  bool yflg=false;
  bool xyswap=false;
  
  if(x<0){
    x=-x; xflg=true;
  }
  if(y<0){
    y=-y; yflg=true;
  }
  if(x<y){
    swap(x,y); xyswap=true;
  }
  
  // k:偶数、x+y:奇数は到達不能
  if(k%2==0&&(x+y)%2==1){
    cout<<-1<<endl;
    return 0;
  }
  
  vector<pii> ans = calc(x,y,k);
  int n = ans.size();
  
  // flgに応じて答えを修正
  if(xyswap) rep(i,n){
    swap(ans[i].first,ans[i].second);
  }
  if(xflg) rep(i,n){
    ans[i].first*=-1;
  }
  if(yflg) rep(i,n){
    ans[i].second*=-1;
  }
  
  cout<<n<<endl;
  rep(i,ans.size()){
    cout<<ans[i].first<<" "<<ans[i].second<<endl;
  }
}
