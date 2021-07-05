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
    vector<int> ex(11);
    ex[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        ex[i] = ex[i-1] * i;
    }
    int p;
    cin >> p;
    int ans = 0;
    int i = 10;
    while (p) {
        if (ex[i] <= p) {
            p -= ex[i];
            ans++;
        }
        else i--;
    }
    cout << ans << endl;
    return 0;
}