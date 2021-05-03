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
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<fenwick_tree<int>> cnt(26, fenwick_tree<int>(n));
    rep(i,n) {
        int j = s[i] - 'a';
        cnt[j].add(i, 1);
    }
    rep(i,q) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            char c;
            cin >> p >> c;
            --p;
            int prev = s[p] - 'a';
            int now = c - 'a';
            s[p] = c;
            cnt[prev].add(p, -1);
            cnt[now].add(p, 1);
        }
        else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            int dup = 0;
            rep(j,26) {
                dup += max(0, cnt[j].sum(l, r+1) - 1);
            }
            cout << r-l+1-dup << endl;
        }
    }
    return 0;
}