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

ll f(ll x) {
    ll res = 1;
    while (x) {
        res *= x%10;
        x /= 10;
    }
    return res;
}

bool test(ll x, ll b) {
    return x - f(x) == b;
}

vector<vector<vector<int>>> digits(11);

void init() {
    rep(i,10) digits[0].push_back({i});
    rep(i, 10) {
        for (auto digit: digits[i]) {
            for (int j = digit.back(); j < 10; ++j) {
                digit.push_back(j);
                digits[i+1].push_back(digit);
                digit.pop_back();
            }
        }
    }
}

int main() {
    ll n, b;
    cin >> n >> b;
    init();
    int ans = 0;
    vector<ll> allAns;
    rep(i, 11) {
        for (auto digit: digits[i]) {
            ll p = 1;
            for (auto d: digit) p *= d;
            ll m = b + p;
            if (n < m) continue;
            vector<int> mdigit;
            while(m) {
                mdigit.push_back(m%10);
                m /= 10;
            }
            if (mdigit.size() != i+1) continue;
            sort(mdigit.begin(), mdigit.end());
            bool ok = true;
            rep(j, i+1) {
                if (digit[j] != mdigit[j]) ok = false;
            }
            if (ok) {
                ans++;
                allAns.push_back(b + p);
            }
        }
    }
    cout << ans << endl;
    // for (auto x: allAns) {
    //     assert(test(x, b));
    //     cout << x << ' ';
    // }
    // cout << endl;
    return 0;
}