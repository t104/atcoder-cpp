#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

ll a, b, c, d;
map<ll, ll> memo;

ll solve(ll n) {
    if(n == 0) return 0;
    if(n == 1) return d;
    if(memo.count(n)) return memo[n];
    
    ll l2 = (n/2)*2;
    ll r2 = ((n+1)/2)*2;
    ll l3 = (n/3)*3;
    ll r3 = ((n+2)/3)*3;
    ll l5 = (n/5)*5;
    ll r5 = ((n+4)/5)*5;

    ll res = 1e18;
    if(n < res/d) res = n*d;
    res = min(res, llabs(l2-n)*d + a + solve(l2/2));
    res = min(res, llabs(r2-n)*d + a + solve(r2/2));
    res = min(res, llabs(l3-n)*d + b + solve(l3/3));
    res = min(res, llabs(r3-n)*d + b + solve(r3/3));
    res = min(res, llabs(l5-n)*d + c + solve(l5/5));
    res = min(res, llabs(r5-n)*d + c + solve(r5/5));

    memo[n] = res;

    return res;
}

int main() {
    int t;
    cin >> t;
    vector<vector<ll>> input(t, vector<ll>(5));
    rep(i, t) {
        rep(j, 5) {
            cin >> input.at(i).at(j);
        }
    }
    rep(i, t) {
        memo.clear();
        ll n = input.at(i).at(0);
        a = input.at(i).at(1);
        b = input.at(i).at(2);
        c = input.at(i).at(3);
        d = input.at(i).at(4);
        cout << solve(n) << endl;
    }
    return 0;
}