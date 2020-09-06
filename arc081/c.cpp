#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.rbegin(), a.rend());
    ll h = 0, w = 0;
    rep(i,n-1) {
        if (a.at(i) == a.at(i+1) && h == 0) {
            h = a.at(i);
            i += 2;
        }
        if (i < n && a.at(i) == a.at(i+1)) {
            w = a.at(i);
            break;
        }
    }
    cout << h * w << endl;
    return 0;
}