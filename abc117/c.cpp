#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i,m) cin >> x.at(i);
    sort(x.begin(), x.end());
    if (m <= n) {
        cout << 0 << endl;
        return 0;    
    }
    
    int ans = x.at(m-1) - x.at(0);
    vector<int> distance(m-1);
    rep(i,m-1) {
        distance.at(i) = x.at(i+1) - x.at(i);
    }
    sort(distance.rbegin(), distance.rend());
    rep(i,n-1) ans -= distance.at(i);
    cout << ans << endl;
    
    return 0;
}