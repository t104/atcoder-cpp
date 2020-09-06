#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int m[200005];
int f(int n){
  if(n==0) return 0;
  if(m[n]>0) return m[n];
  return m[n]=f(n%__builtin_popcount(n))+1;
}
int main() {
  int n; string x;
  cin >> n >> x;
  reverse(x.begin(),x.end());
  int b=0;
  rep(i,n) if(x[i]=='1') ++b;
  vector<int> v0(n),v1(n);
  int d0=1,d1=1;
  ll s0=0,s1=0;
  rep(i,n){
    v0[i]=d0;
    v1[i]=d1;
    d0<<=1;d0%=b+1;
    if(b!=1) d1<<=1, d1%=b-1;
    if(x[i]=='1') s0+=v0[i], s1+=v1[i];
  }
  vector<int> ans(n);
  rep(i,n){
    if(x[i]=='0'){
      ans[i] = f((s0+v0[i])%(b+1))+1;
    }else{
      ans[i] = b==1 ? 0 : f((s1-v1[i])%(b-1))+1;
    }
  }
  reverse(ans.begin(),ans.end());
  rep(i,n) cout << ans[i] << endl;
}
