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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    rep(i,n) {
        cin >> a[i];
        a[i]--;
    }
    int ans = INF;
    rep(i,10) {
        rep(j,10) {
            if (i == j) continue;
            int sum = 0;
            rep(k,n) {
                if (k%2 == 0) {
                    if (a[k] != i) sum += c;
                }
                else if (a[k] != j) sum += c;
            }
            chmin(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}

