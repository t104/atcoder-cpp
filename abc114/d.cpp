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

int main() {
    int n;
    cin >> n;
    vector<P> factors;
    vector<int> numbers(n);
    rep(i,n) numbers[i] = i+1;
    rep(i,n) {
        if (numbers[i] == 1) continue;
        int p = numbers[i];
        int cnt = 0;
        for (int j = i; j < n; ++j) {
            while (numbers[j]%p == 0) {
                numbers[j] /= p;
                cnt++;
            }
        }
        factors.emplace_back(p, cnt);
    }
    ll ans = 0;
    int m3 = 0, m5 = 0, m15 = 0, m25 = 0, m75 = 0;
    for (auto p: factors) {
        if (2 <= p.second) m3++;
        if (4 <= p.second) m5++;
        if (14 <= p.second) m15++;
        if (24 <= p.second) m25++;
        if (74 <= p.second) m75++;
    }
    ans += m75;
    if (1 < m3) ans += (m3-1) * m25;
    if (1 < m5 && 2 < m3) ans += (m3-2) * (m5-1) * m5 / 2;
    if (1 < m5) ans += (m5-1) * m15;
    cout << ans << endl;
    return 0;
}