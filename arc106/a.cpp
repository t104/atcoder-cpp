#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

const ll max_n = 1e18 + 5;

int main() {
    ll n;
    cin >> n;
    ll ax = 1, bx = 1;
    for (int a = 1 ; ax < max_n; ++a) {
        ax *= 3;
        bx = 1;
        for (int b = 1; bx < max_n - ax; ++b) {
            bx *= 5;
            if (ax + bx == n) {
                printf("%d %d\n", a, b);
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}