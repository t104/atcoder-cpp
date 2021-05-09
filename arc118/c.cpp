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

// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
    int n;
    vector<int> f, primes;
    Sieve(int n=1):n(n), f(n+1) {
        f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  vector<pair<ll,int>> factor(ll x) {
    vector<pair<ll,int>> res;
    for (int p : primes) {
      int y = 0;
      while (x%p == 0) x /= p, ++y;
      if (y != 0) res.emplace_back(p,y);
    }
    if (x != 1) res.emplace_back(x,1);
    return res;
  }
};

const int MX = 10000;

vector<int> factors;

bool ok(int x) {
    for (auto f: factors) {
        if (x%f == 0) return false;
    }
    return true;
}

bool test(vector<int> ans) {
    int n = ans.size();
    rep(i,n-1) {
        if (ans[i] == ans[i+1]) {
            return false;
        }
        if (MX < ans[i]) {
            return false;
        }
    }
    
    int g = ans[0];
    rep(i,n) g = gcd(g, ans[i]);
    if (1 < g) {
        return false;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (gcd(ans[i], ans[j]) == 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans(n);
    int x = 0;
    Sieve sv(1000000);

    while (x < n) {
        int ai = 6*(x+1);
        ans[x] = ai;
        x++;
        if (MX <= ai+6) break;
    }
    factors.push_back(6);

    for (int i = 2; i < 1000; ++i) {
        int p = sv.primes[i];
        for (auto pi: {2*p, 3*p}) {
            int j = 1;
            while (x < n) {
                int ai = pi*j;
                if (ok(ai)) {
                    ans[x] = ai;
                    x++;
                }
                if (MX < ai+pi) break;
                j++;
            }
            factors.push_back(pi);
        }
    }

    bool add10 = true, add15 = true;
    rep(i,n) {
        if (ans[i] == 10) add10 = false;
        if (ans[i] == 15) add15 = false;
    }

    sort(ans.begin(), ans.end());
    if (add10) ans[n-2] = 10;
    if (add15) ans[n-1] = 15;

    rep(i,n) cout << ans[i] << ' ';
    cout << endl;

    // assert(test(ans));
    return 0;
}