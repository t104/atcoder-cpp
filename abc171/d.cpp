#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(100005);
    rep(i,n) {
        int ai;
        cin >> ai;
        a.at(ai)++;
    }
    
    ll sum = 0;
    rep(i, 100001) {
        sum += (ll) a.at(i) * i;
    }

    int q;
    cin >> q;
    queue<ll> ans;
    rep(i, q) {
        int b, c;
        cin >> b >> c;
        sum -= (ll) b * a.at(b);
        sum += (ll) c * a.at(b);
        a.at(c) += a.at(b);
        a.at(b) = 0;
        ans.push(sum);
    }

    while(!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop();
    }
    return 0;
}