#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

int op (int x, int y) {
    return x + y;
}

int e () {
    return 0;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<P> line;
    int prev = 0;
    int len = 0;
    rep(i,n) {
        if (prev == s.at(i) - '0') len++;
        else {
            line.push_back({prev, len});
            prev = s.at(i) - '0';
            len = 1;
        }
    }
    line.push_back({prev, len});
    int nline = line.size();
    segtree<int, op, e> seg(nline);
    rep(i, nline) seg.set(i, line.at(i).second);
    int ans = 0;
    rep(l, nline) {
        int r = l + 2*k;
        if (line.at(l).first == 0) r--;
        if (nline <= r) {
            chmax(ans, seg.prod(l, nline));
            break;
        }
        chmax(ans, seg.prod(l, r+1));
    }
    cout << ans << endl;

    return 0;
}