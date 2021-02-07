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
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

map<int, int> gcds;

vector<int> divisors(int x) {
    vector<int> res;
    for (int i = 1; i*i <= x; ++i) {
        if (x%i != 0) continue;
        res.push_back(i);
        if (x/i != i) res.push_back(x/i);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int mina = INF;
    rep(i,n) {
        chmin(mina, a[i]);
        for (auto d : divisors(a[i])) {
            gcds[d] = gcd(gcds[d], a[i]);
        }
    }

    ll ans = 0;
    for (auto p : gcds) {
        if (p.first <= mina && p.first == p.second) {
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}