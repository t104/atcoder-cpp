#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

vector<ll> a = {1}, p = {1};

ll f(int n, ll x) {
    // one patty
    if (n == 0) return 1;
    // one ban
    if (x == 1) return 0;
    
    if (x <= a.at(n-1) + 1) return f(n-1, x-1);
    if (x == a.at(n-1) + 2) return p.at(n-1) + 1;
    if (x <= (a.at(n-1) + 1) * 2) return p.at(n-1) + 1 + f(n-1, x-a.at(n-1)-2);
    return p.at(n-1) * 2 + 1;
}

int main() {
    int n;
    ll x;
    cin >> n >> x;

    rep(i,n)  {
        a.push_back((ll) a.at(i) * 2 + 3);
        p.push_back((ll) p.at(i) * 2 + 1);
    }
    ll ans = f(n,x);
    cout << ans << endl;
    return 0;
}