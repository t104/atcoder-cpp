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
using P = pair<int,int>;

const int MX = 1000005;

int main() {
    int k;
    cin >> k;
    int x = 7;
    rep(i,MX) {
        x %= k;
        if (x == 0) {
            cout << i+1 << endl;
            return 0;
        }
        x *= 10;
        x += 7;
    }
    cout << -1 << endl;
    return 0;
}