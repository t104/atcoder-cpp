#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}
using ll = long long;
using ld = long double;
using P = pair<int,int>;


const map<char, int> mp = {
    {'B', 0},
    {'W', 1},
    {'R', 2}
};
const map<int, char> rev = {
    {0, 'B'},
    {1, 'W'},
    {2, 'R'}
};

vector<int> dfs(vector<int> &vt) {
    int n = vt.size();
    if (n == 1) return vt;
    vector<int> res(n-1);
    rep(i,n-1) {
        res[i] = (6-vt[i]-vt[i+1])%3;
    }
    return dfs(res);
}

struct combination {
  int n;
  vector<ll> f, g;
  combination(int n): n(n) {
    f.resize(n+1);
    g.resize(n+1);
    g[0] = 1;
    for (int i = n, j = 1; j <= n; --i, ++j) {
      // cout << i << ' ' << j << ' ' << endl;
      int x = i, y = j;
      f[j] += f[j-1];
      while (x%3 == 0) {
        x /= 3;
        f[j]++;
      }
      while (y%3 == 0) {
        y /= 3;
        f[j]--;
      }
      x %= 3;
      y %= 3;
      g[j] = (g[j-1] * x * y) % 3;
    }
  }

  ll get(int r) {
    if (0 < f[r]) return 0;
    return g[r];
  }
};

int main() {
    int n;
    cin >> n;
    vector<int> base(n);
    rep(i,n) {
        char c;
        cin >> c;
        base[i] = mp.at(c);
    }

    combination c(n-1);
    ll ans = 0;
    rep(i,n) {
      // cout << c.get(i) << ' ' << base[i] << endl;
      ans += c.get(i) * base[i];
      ans %= 3;
    }
    if (n%2 == 0) {
      ans = (3 - ans) % 3;
    }
    cout << rev.at(ans) << endl;
    return 0;
}