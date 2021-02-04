//GIVE ME AC!!!!!!!!!!!!!!!!!
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using namespace atcoder;
//素数判定 O(√N)
ll prime(ll num){
    if (num < 2){
        return 0;
    }
    else if (num == 2){
        return 1;
    }
    else if (num % 2 == 0){
        return 0;
    }
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}
//素因数分解(約数列挙) O(√N)
vector<ll> divisor(ll n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
//約数個数 O(√N)
ll divisor_num(ll a) {
  ll ans=1;
  for (int i = 2; i <= sqrt(a); i++) {
    ll cnt = 0;
    while (a%i==0) {
      cnt++;
      a/=i;
    }
    ans*=(cnt+1);
    if (a == 1) break;
  }
  if (a != 1) ans *= 2;
return ans;
}
//最大公約数
ll gcd(ll x,ll y){
    if(x<y) swap(x,y);
    //xの方が常に大きい
    ll r;
    while(y>0){
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
//最小公倍数
ll lcm(ll x,ll y){
    return (ll)(x/gcd(x,y))*y;
}
//転倒数
ll merge_cnt(vector<ll> &a) {
    ll n = a.size();
    if (n <= 1) { return 0; }
    ll cnt = 0;
    vector<ll> b(a.begin(), a.begin()+n/2);
    vector<ll> c(a.begin()+(n/2), a.end());
    cnt += merge_cnt(b);
    cnt += merge_cnt(c);
    ll ai = 0, bi = 0, ci = 0;
    while (ai < n) {
        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
int main(){
  ll n;
  cin>>n;
  vector<int>a(n);
  rep(i,n){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  if(n%2==1){
    ll sum=-a[n/2]-a[n/2+1];
  ll ans=a[n/2]+a[n/2-1];
  rep(i,n/2){
    sum-=2*a[i];
  }
    for(int i=n/2;i<n;i++){
      sum+=2*a[i];
    }
  rep(i,n/2+1){
      ans-=2*a[i];
    }
  for(int i=n/2+1;i<n;i++){
    ans+=2*a[i];
  }
    cout<<max(ans,sum)<<endl;
  }
  else{
    ll ans=a[n/2-1]-a[n/2];
    rep(i,n/2){
      ans-=2*a[i];
    }
    for(int i=n/2;i<n;i++){
      ans+=2*a[i];
    }
    cout<<ans<<endl;
  }
}