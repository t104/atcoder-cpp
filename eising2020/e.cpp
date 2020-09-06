#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using tup = tuple<int,int,int>;

ll solve() {
    int n;
    cin >> n;
    vector<tup> lr, rl;
    rep(i,n) {
        int k, l, r;
        cin >> k >> l >> r;
        if (l < r) lr.push_back(make_tuple(k, l, r));
        else rl.push_back(make_tuple(k, l, r));
    }
    ll sum = 0;
    for (auto cam : rl) sum += get<2>(cam);
    for (auto cam : lr) sum += get<1>(cam);

    sort(rl.begin(), rl.end());
    sort(lr.rbegin(), lr.rend());
    priority_queue<int, vector<int>, greater<int>> querl;
    int ki = get<0>(rl.at(0));
    for (auto cam : rl) {
        int d = get<1>(cam) - get<2>(cam);
        if (ki == get<0>(cam)) {
            querl.push(d);
            continue;
        }
        while (ki < querl.size()) querl.pop();
        ki = get<0>(cam);
        querl.push(d);
    }
    while (ki < querl.size()) querl.pop();

    priority_queue<int, vector<int>, greater<int>> quelr;
    ki = get<0>(lr.at(0));
    for (auto cam : lr) {
        int d = get<2>(cam) - get<1>(cam);
        if (ki == get<0>(cam)) {
            quelr.push(d);
            continue;
        }
        while (n-ki < quelr.size()) quelr.pop();
        ki = get<0>(cam);
        quelr.push(d);
    }
    while (n-ki < quelr.size()) quelr.pop();

    while (!querl.empty()) {
        sum += querl.top();
        querl.pop();
    }
    while (!quelr.empty()) {
        sum += quelr.top();
        quelr.pop();
    }
    return sum;
}

int main() {
    int t;
    cin >> t;
    vector<ll> ans(t);
    rep(i,t) ans.at(i) = solve();
    rep(i,t) cout << ans.at(i) << endl;
    return 0;
}