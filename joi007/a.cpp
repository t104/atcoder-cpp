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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<P> cnt;
    cnt.emplace_back(a[0], 1);
    for (int i = 1; i < n; ++i) {
        if (cnt.back().first == a[i]) {
            cnt.back().second++;
            continue;
        }
        if (i%2 == 0) {
            cnt.emplace_back(a[i], 1);
            continue;
        }

        int s = cnt.size();
        if (2 <= s) {
            cnt[s-2].second += cnt[s-1].second + 1;
            cnt.pop_back();
            continue;
        }
        cnt[s-1].first = a[i];
        cnt[s-1].second++;
    }

    int ans = 0;
    for (auto c : cnt) {
        if (c.first == 0) {
            ans += c.second;
        }
    }
    cout << ans << endl;
    return 0;
}