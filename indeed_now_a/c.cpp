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

const int MX = 1000005;

int main() {
    int n;
    cin >> n;
    vector<int> point(MX);
    rep(i,n) {
        int s;
        cin >> s;
        point[s]++;
    }
    rep(i,MX-1) point[i+1] += point[i];

    int q;
    cin >> q;
    auto ok = [&](int x, int k) {
        return point.back() - point[x-1] <= k;
    };
    rep(i,q) {
        int k;
        cin >> k;
        int l = 1, r = MX-1;
        if (ok(l,k)) {
            cout << 0 << endl;
            continue;
        }
        while (l+1 < r) {
            int m = (l+r)/2;
            if (ok(m, k)) r = m;
            else l = m;
        }
        cout << r << endl;
    }
    return 0;
}