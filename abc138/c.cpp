#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<double> v(n);
    rep(i, n) cin >> v.at(i);
    sort(v.begin(), v.end());
    double ans = v.at(0);
    for(int i = 1; i < n; i++) {
        ans += v.at(i) * pow(2, i - 1);
    }
    ans /= pow(2, n-1);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
