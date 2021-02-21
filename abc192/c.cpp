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
    ll n;
    int k;
    cin >> n >> k;
    
    ll a = n;
    rep(i,k) {
        vector<int> x;
        while (a) {
            x.push_back(a%10);
            a /= 10;
        }
        sort(x.begin(), x.end());
        ll g1 = 0, g2 = 0;
        ll d = 1;
        for (auto xi: x) {
            g1 += d*xi;
            d *= 10;
        }
        reverse(x.begin(), x.end());

        d = 1;
        for (auto xi: x) {
            g2 += d*xi;
            d *= 10;
        }

        a = g1 - g2;
    }

    cout << a << endl;

    return 0;
}