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

const int MX = 200005;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = MX; 0 < i; --i) {
        int l = (a/i)*i;
        if (a%i) l += i;
        if (l+i <= b) {
            cout << i << endl;
            return 0;
        }
    }
    throw;
    return 0;
}