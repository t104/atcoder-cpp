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

int solve(int a, int b) {
    if (15 <= a+b && 8 <= b) return 1;
    if (10 <= a+b && 3 <= b) return 2;
    if (3 <= a+b) return 3;
    return 4;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a,b) << endl;
    return 0;
}