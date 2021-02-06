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

const int MX = 200005;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<int> cnt1(n+1), cnt2(n+1);
    rep(i,n) cnt1[a[i]]++;
    rep(i,n) cnt2[b[i]]++;
    rep(i,n+1) {
        if (n < cnt1[i] + cnt2[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    vector<int> ord(n+1);
    rep(i,n+1) ord[i] = i;
    sort(ord.begin(), ord.end(), [&](int x, int y) {
        return cnt1[y] + cnt2[y] < cnt1[x] + cnt2[x];
    });
    int idx = 0;
    vector<int> ans1(n), ans2(n);
    for (auto i : ord) {
        while (cnt1[i]) {
            ans1[idx++] = i;
            --cnt1[i];
            if (idx == n) break;
        }
        if (idx == n) break;
        while (cnt2[i]) {
            ans2[idx++] = i;
            --cnt2[i];
            if (idx == n) break;
        }
        if (idx == n) break;
    }
    idx = 0;
    for (auto i : ord) {
        rep(j,cnt1[i]) {
            while(ans1[idx]) ++idx;
            ans1[idx] = i;
        }
    }
    idx = 0;
    for (auto i : ord) {
        rep(j,cnt2[i]) {
            while(ans2[idx]) ++idx;
            ans2[idx] = i;
        }
    }
    vector<int> ans(n);
    rep(i,n) ans[i] = i;
    sort(ans.begin(), ans.end(), [&](int u, int v) {
        return ans1[u] < ans1[v];
    });
    rep(i,n) cout << ans2[ans[i]] << ' ';

    return 0;
}