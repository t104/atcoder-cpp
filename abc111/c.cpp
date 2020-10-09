#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T> void chmax(T &a, T b) { a = max(a, b); }
template<typename T> void chmin(T &a, T b) { a = min(a, b); }

int main() {
    int n;
    cin >> n;
    map<int,int> v1,v2;
    rep(i,n) {
        int vi;
        cin >> vi;
        if (i%2 == 0) v1[vi]++;
        else v2[vi]++;
    }
    vector<P> vv1, vv2;
    for (auto v : v1) vv1.push_back(v);
    for (auto v : v2) vv2.push_back(v);
    sort(vv1.begin(), vv1.end(),[&](P x, P y) {
        return y.second < x.second;
    });
    sort(vv2.begin(), vv2.end(),[&](P x, P y) {
        return y.second < x.second;
    });
    int ans = n;
    chmin(ans, n - vv1.at(0).second);
    chmin(ans, n - vv2.at(0).second);
    if (vv1.at(0).first != vv2.at(0).first) {
        chmin(ans, n - vv1.at(0).second - vv2.at(0).second);
    }
    if (1 < vv1.size()) chmin(ans, n - vv2.at(0).second - vv1.at(1).second);
    if (1 < vv2.size()) chmin(ans, n - vv1.at(0).second - vv2.at(1).second);
    cout << ans << endl;
    return 0;
}