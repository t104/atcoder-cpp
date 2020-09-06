#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h.at(i);
    sort(h.begin(), h.end());
    int dmin = 1e9;
    rep(i,n-k+1) {
        int d = h.at(i+k-1) - h.at(i);
        dmin = min(dmin, d);
    }
    cout << dmin << endl;
    return 0;
}