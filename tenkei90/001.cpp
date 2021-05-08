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
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> a(N+1);
    rep(i,N) cin >> a[i];
    a[N] = L;

    int l = 0, r = INF;
    auto ok = [&](int x) {
        int s = 0, cnt = 0;
        for (auto ai: a) {
            if (x <= ai-s) {
                s = ai;
                cnt++;
            }
        }
        return K+1 <= cnt;
    };
    while (l+1 < r) {
        int m = (l+r)/2;
        if (ok(m)) l = m;
        else r = m;
    }
    cout << l << endl;
    return 0;
}