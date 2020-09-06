#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<P> x(n);
    rep(i,n) {
        int xi;
        cin >> xi;
        x.at(i) = {xi, i};
    }
    sort(x.begin(), x.end());
    vector<int> ans(n);
    rep(i,n) {
        if (i < n/2) ans.at(x.at(i).second) = x.at(n/2).first;
        else ans.at(x.at(i).second) = x.at(n/2 - 1).first;
    }
    rep(i,n) cout << ans.at(i) << endl;
    return 0;
}