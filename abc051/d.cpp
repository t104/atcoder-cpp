#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

// auto mod int
// https://github.com/atcoder-live/library/blob/master/mint.cpp
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

int main() {
    int n, k;
    cin >> n >> k;
    vector<P> a(n);
    int pos = 0;
    rep(i,n) {
        int ai;
        cin >> ai;
        if (ai < 0) {
            a.at(i) = make_pair(-ai, -1);
        }
        else {
            a.at(i) = make_pair(ai, 1);
            pos++;
        }
    }
    sort(a.begin(), a.end());

    mint ans = 1;
    if(n == k || pos == 0) {
        rep(i,k) ans *= a.at(i).first * a.at(i).second;
        cout << ans << endl;
        return 0;
    }

    reverse(a.begin(), a.end());
    int neg = -1, i = 0;
    vector<int> b;
    while (b.size() < k) {
        if (a.at(i).second == 1) {
            b.push_back(a.at(i).first*a.at(i).second);
        }
        else if (b.size() < k-1 && neg != -1) {
            b.push_back(-neg);
            b.push_back(a.at(i).first*a.at(i).second);
            neg = -1;
        }
        else {
            neg = a.at(i).first;
        }
        i++;
    }
    rep(j, k) {
        ans *= b.at(j);
    }
    cout << ans << endl;
    return 0;
}