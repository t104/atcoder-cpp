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

dsu uf;
string s;
int N, core_length;

void ng() {
    cout << "impossible" << endl;
    exit(0);
}

void merge(int l, int r, int k) {
    if (k == 0) {
        core_length = r-l;
        if (core_length == 1) ng();
        return;
    }
    if (0 < k && l == r) ng();

    if ((r-l)%2 == 0) {
        int mid = (r-l)/2;
        rep(i, mid) {
            uf.merge(l+i, r-1-i);
        }
        merge(l, l+mid, k-1);
        merge(l+mid, r, k-1);
    }
    else {
        int mid = (r-l)/2;
        rep(i, mid) {
            uf.merge(l+i, r-1-i);
        }
        merge(l, l+mid, k-1);
        merge(l+mid+1, r, k-1);
    }
}

int main() {
    int k;
    cin >> k >> s;
    N = s.size();
    uf = dsu(N);
    merge(0, N, k);

    auto gs = uf.groups();
    int n = gs.size();
    vector<vector<P>> cnt(n, vector<P>(26));
    vector<int> choose(N), d(N);
    int ans = 0, to_fix = INF;
    rep(i,n) rep(j,26) cnt[i][j] = {gs[i].size(), j};
    rep(i,n) {
        for (auto j: gs[i]) {
            cnt[i][s[j] - 'a'].first--;
        }
        sort(cnt[i].begin(), cnt[i].end());
        choose[uf.leader(gs[i][0])] = cnt[i][0].second;
        d[uf.leader(gs[i][0])] = cnt[i][1].first - cnt[i][0].first;
        ans += cnt[i][0].first;
    }
    int not_same_cnt = 0;
    for (int i = 0, j = core_length - 1; i < j; ++i, --j) {
        if (choose[uf.leader(i)] == choose[uf.leader(j)]) {
            chmin(to_fix, d[uf.leader(i)]);
            chmin(to_fix, d[uf.leader(j)]);
        }
        else not_same_cnt++;
    }
    if (2 <= core_length && 0 == not_same_cnt) {
        ans += to_fix;
    }
    cout << ans << endl;
    return 0;
}