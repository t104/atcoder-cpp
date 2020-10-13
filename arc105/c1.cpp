#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}


template<typename F>
void all_permutations(Int n,F f){
  vector<Int> vs(n);
  iota(vs.begin(),vs.end(),0);
  do f(vs); while(next_permutation(vs.begin(),vs.end()));
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,m;
  cin>>n>>m;
  auto ws=read(n);

  vector<Int> ls(m),vs(m);
  for(Int i=0;i<m;i++) cin>>ls[i]>>vs[i];

  if(*max_element(ws.begin(),ws.end())>*min_element(vs.begin(),vs.end()))
    drop(-1);

  const Int sz=1<<n;
  vector<Int> len(sz,0);
  for(Int bit=0;bit<sz;bit++){
    Int sum=0;
    for(Int i=0;i<n;i++)
      if((bit>>i)&1) sum+=ws[i];

    for(Int i=0;i<m;i++)
      if(vs[i]<sum) chmax(len[bit],ls[i]);
  }

  Int ans=1e18;
  auto f=[&](auto ps){
    vector<Int> dp(n,0);
    for(Int i=0;i<n;i++){
      Int bit=0;
      for(Int j=i;j<n;j++){
        bit|=1<<ps[j];
        chmax(dp[j],dp[i]+len[bit]);
      }
    }
    chmin(ans,dp.back());
  };
  all_permutations(n,f);
  cout<<ans<<newl;
  return 0;
}
