#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    int now = 0, r = n;
    vector<int> a(m), b(m);
    rep(i,m) cin >> a.at(i) >> b.at(i);
    rep(i,m) {
        r -= a.at(i) - now;
        if (r <= 0) {
            cout << "No" << endl;
            return 0;
        }
        r += b.at(i) - a.at(i);
        chmin(r, n);
        now = b.at(i);
    }
    r -= t - now;
    if (r <= 0) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}