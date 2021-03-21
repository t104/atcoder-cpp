// 2021-03-21 13:09:05
// clang-format off
#include <bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

// clang-format on
void answer() {
    string s;
    int x, y;
    cin >> s >> x >> y;
    s += 'T';
    x += 20000;
    y += 20000;
    vector<bitset<40000>> bs(2);
    bs[0][20000] = bs[1][20000] = true;
    int sz = s.size();
    int sf = 0;
    for(; s[sf] == 'F'; sf++)
        x--;
    int t = 0, cur = 0;
    REP(i, sf, sz) {
        if(s[i] == 'F') {
            cur++;
        } else {
            bitset<40000> p;
            swap(bs[t], p);
            bs[t] |= (p >> cur);
            bs[t] |= (p << cur);
            cur = 0;
            t = 1 - t;
        }
    }
    if(bs[0][x] && bs[1][y]) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    answer();
    return 0;
}