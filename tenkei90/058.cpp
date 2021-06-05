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

int f(int x) {
    int y = 0;
    int tmp = x;
    while (tmp) {
        y += tmp % 10;
        tmp /= 10;
    }
    return (x+y) % 100000;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> dp(100000);
    rep(i,100000) {
        dp[i] = f(i);
    }
    vector<int> a;
    int x = n;
    while (k) {
        auto p = find(a.begin(), a.end(), x);
        if (p != a.end()) {
            int sz = a.size();
            int s = p - a.begin();
            int r = k % (sz-s);
            cout << a[s+r] << endl;
            return 0;
        }
        a.push_back(x);
        x = dp[x];
        k--;
    }
    cout << x << endl;
    return 0;
}