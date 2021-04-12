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

void dame() {
    cout << "UNSOLVABLE" << endl;
    exit(0);
}

int main() {
    vector<string> s(3);
    rep(i,3) cin >> s[i];
    map<char, int> all;
    for (auto si: s) {
        for (auto c: si) {
            all[c] = 0;
        }
    }
    if (10 < all.size()) dame();
    vector<int> d(10);
    rep(i,10) d[i] = i;
    do {
        bool ok = true;
        vector<ll> x(3);
        int idx = 0;
        for (auto &p: all) {
            p.second = d[idx];
            idx++;
        }
        for (auto &si: s) {
            if (all.at(si[0]) == 0) ok = false;
        }
        rep(i,3) {
            for (auto c: s[i]) {
                x[i] *= 10;
                x[i] += all.at(c);
            }
        }
        if (ok && x[0] + x[1] == x[2]) {
            for (auto xi: x) cout << xi << endl;
            return 0;
        }
    } while(next_permutation(d.begin(), d.end()));
    dame();
    return 0;
}