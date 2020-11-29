#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
using T = tuple<int,int,int>;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 50;
const int C = MX/2;
const int C2 = C/2;
const int di[] = {1,1,-1,-1}, dj[] = {1,-1,-1,1};

int dp[MX][MX][4];

int dist(P a, P b) { return abs(a.fi-b.fi)+abs(a.se-b.se);}

void solve() {
  P a, b, c;
  cin>>a>>b>>c;
  if (dist(a,c) == 2) swap(b,c);
  if (dist(b,c) == 2) swap(a,c);
  P d(a.fi+b.fi-c.fi, a.se+b.se-c.se);
  int v = 0;
  if (c.fi < d.fi && c.se < d.se) v = 0;
  if (c.fi < d.fi && c.se > d.se) v = 1;
  if (c.fi > d.fi && c.se > d.se) v = 2;
  if (c.fi > d.fi && c.se < d.se) v = 3;
  // cerr<<c<<" "<<d<<" "<<v<<endl;

  int l = min(abs(c.fi),abs(c.se));
  l = max(l-C2, 0);
  int ans = l;
  if (c.fi < 0) c.fi += l; else c.fi -= l;
  if (c.se < 0) c.se += l; else c.se -= l;
  {
    l = abs(c.fi);
    l = max(l-C+3, 0);
    ans += l;
    if (c.fi < 0) c.fi += l; else c.fi -= l;
  }
  {
    l = abs(c.se);
    l = max(l-C+3, 0);
    ans += l;
    if (c.se < 0) c.se += l; else c.se -= l;
  }
  ans *= 2;
  // cerr<<c<<" "<<ans<<endl;
  ans += dp[C+c.fi][C+c.se][v];
  cout<<ans<<endl;
}

int main() {
  rep(i,MX)rep(j,MX)rep(k,4) dp[i][j][k] = INF;
  queue<T> q;
  auto push = [&](int i, int j, int k, int x) {
    if (i < 0 || j < 0 || i >= MX || j >= MX) return;
    if (dp[i][j][k] != INF) return;
    dp[i][j][k] = x;
    q.emplace(i,j,k);
  };
  push(C,C,0,0);

  while (sz(q)) {
    // auto [i,j,k] = q.front(); q.pop(); // <- why compile error?
    int i, j, k; tie(i,j,k) = q.front(); q.pop();
    int nd = dp[i][j][k]+1;
    rrep(s,3) {
      int nk = (k+s)%4;
      push(i+(di[k]+di[nk^2])/2, j+(dj[k]+dj[nk^2])/2, nk, nd);
      if (s&1) push(i+(di[k]+di[nk])/2, j+(dj[k]+dj[nk])/2, k^2, nd);
    }
    push(i,j,k^1,nd);
    push(i,j,k^3,nd);
  }

  int ts;
  scanf("%d",&ts);
  rep(ti,ts) solve();
  return 0;
}
