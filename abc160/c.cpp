#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int k,n;
    cin >> k >> n;
    vector<int> v(n);
    rep(i,n) cin >> v.at(i);
    vector<int> dif(n);
    rep(i,n-1) dif.at(i) = v.at(i+1) - v.at(i);
    dif.at(n-1) = k + v.at(0) - v.at(n-1);

    int max = *max_element(dif.begin(), dif.end());
    int ans = k - max;
    cout << ans << endl;
    return 0;
}