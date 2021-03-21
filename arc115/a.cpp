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
    int n, m;
    cin >> n >> m;
    ll odd = 0, even = 0;
    rep(i,n) {
        string s;
        cin >> s;
        int cnt = 0;
        for (auto c: s) {if (c == '1') cnt++;}
        if (cnt%2 == 0) even++;
        else odd++;
    }
    cout << odd * even << endl;
    return 0;
}