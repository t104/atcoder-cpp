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

int cnt;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    cnt++;
    return gcd(b, a%b);
}

P dcg(int a = 1, int b = 0, int c = 0) {
    if (c == 0) return {a, b};
    return dcg(a+b, a, c-1);
}

int main() {
    int n;
    cin >> n;
    cnt = 0;
    P p = dcg(1, 1, n);
    cout << p.first << ' ' << p.second << endl;
    gcd(p.first, p.second);
    assert(cnt == n);
    return 0;
}

