#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

ll f(ll n) {
    if (n%2 == 0) return ((n/2)%2)^n;
    return ((n+1)/2)%2;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << (f(a-1)^f(b)) << endl;
    // cout << f(5) << endl;
    return 0;
}