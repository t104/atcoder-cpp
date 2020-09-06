#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

vector<ll> ans(10, LLONG_MAX);
vector<int> price(4);

void fact(ll &n, ll &cost) {
    while(n % 2 == 0) {
        n /= 2;
        cost += price.at(0);
    }
    while(n % 3 == 0) {
        n /= 3;
        cost += price.at(1);
    }
    while(n % 5 == 0) {
        n /= 5;
        cost += price.at(2);
    }
}

void dfs(int t, ll n, ll now, ll cost) {
    if(now == 1) {
        cost += price.at(3);
        ans.at(t) = min(ans.at(t), cost);
    }
    fact(now, cost);
    dfs()
}


int main() {
    int t;
    cin >> t;
    vector<ll> n(t);
    vector<vector<int>> prices(t, vector<int>(4));
    rep(i, t) {
        cin >> n.at(i);
        rep(j, 4) cin >> prices.at(i).at(j);
    }


    rep(i, t) {
        price = prices.at(i);
        cout << ans.at(i) << endl;
    }
    return 0;
}