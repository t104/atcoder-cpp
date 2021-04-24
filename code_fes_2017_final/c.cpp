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

int diff(int x, int y) {
    return min(abs(x-y), 24-abs(x-y));
}

int main() {
    int n;
    cin >> n;
    vector<int> t(13);
    t[0] = 1;
    rep(i,n) {
        int d;
        cin >> d;
        t[d]++;
    }
    vector<int> common;
    int s = 1;
    rep(i,13) {
        if (3 <= t[i]) {
            cout << 0 << endl;
            return 0;
        }
        if (2 == t[i]) {
            common.push_back(i);
            common.push_back(24-i);
        }
        else if (t[i] == 1) {
            s |= 1<<i;
        }
    }
    int ans = 0;
    for (int i = 0; i < (1<<13); ++i) {
        vector<int> list = common;
        for (int si = 0; si < 13; ++si) {
            if ((~s>>si)&1) continue;
            if ((i>>si)&1) {
                list.push_back(si);
            }
            else {
                list.push_back(24-si);
            }
        }
        sort(list.begin(), list.end());
        int mi = 24;
        int m = list.size();
        rep(j,m) {
            chmin(mi, diff(list[(j+1)%m], list[j]));
        }
        chmax(ans, mi);
    }
    cout << ans << endl;
    return 0;
}