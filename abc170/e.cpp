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

const int MX = 200005;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);

    vector<multiset<int>> s(MX);
    multiset<int> maxs;

    auto getMax = [&](int i) {
        if (s[i].size() == 0) return -1;
        return *s[i].rbegin();
    };
    auto addYochien = [&](int i) {
        int x = getMax(i);
        if (x == -1) return;
        maxs.insert(x);
    };
    auto delYochien = [&](int i) {
        int x = getMax(i);
        if (x == -1) return;
        maxs.erase(maxs.find(x));
    };
    auto addEnji = [&](int i, int x) {
        delYochien(i);
        s[i].insert(x);
        addYochien(i);
    };
    auto delEnji = [&](int i, int x) {
        delYochien(i);
        s[i].erase(s[i].find(x));
        addYochien(i);
    };

    rep(i,n) {
        cin >> a[i] >> b[i];
        addEnji(b[i], a[i]);
    }

    rep(i,q) {
        int c, d;
        cin >> c >> d;
        --c;
        delEnji(b[c], a[c]);
        b[c] = d;
        addEnji(b[c], a[c]);
        int ans = *maxs.begin();
        printf("%d\n", ans);
    }
    return 0;
}