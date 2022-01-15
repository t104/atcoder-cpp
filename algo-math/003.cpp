#include <bits/stdc++.h>
#define INF 1001001001
#define LINF (1LL<<60)
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,int>;
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){ return a > b && (a = b, true); }
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){ return a < b && (a = b, true); }
template<typename T1,typename T2, typename T3> inline bool in(T1 val, T2 l, T3 r){return l <= val && val < r;}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    rep(i,n) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << sum << endl;
    return 0;
}