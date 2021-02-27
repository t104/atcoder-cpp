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
    vector<int> rate(n), belong(n);

    vector<multiset<int>> s(MX);
    multiset<int> mx;

    auto getMax = [&](int yochien) {
        if (s[yochien].size() == 0) return -1;
        return *s[yochien].rbegin();
    };

    auto rmMax = [&](int i) {
        if (i == -1) return;
        mx.erase(mx.find(i));
    };

    auto addMax = [&](int i) {
        if (i == -1) return;
        mx.insert(i);
    };

    auto addEnji = [&](int i, int yochien) {
        belong[i] = yochien;
        rmMax(getMax(yochien));
        s[yochien].insert(rate[i]);
        addMax(getMax(yochien));
    };

    auto rmEnji = [&](int i) {
        int yochien = belong[i];
        rmMax(getMax(yochien));
        s[yochien].erase(s[yochien].find(rate[i]));
        addMax(getMax(yochien));
    };

    rep(i,n) {
        int b;
        cin >> rate[i] >> b;
        b--;
        addEnji(i, b);
    }

    rep(i,q) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        rmEnji(c);
        addEnji(c, d);
        printf("%d\n", *mx.begin());
    }
    return 0;
}