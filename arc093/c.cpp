#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    for (int i = 1; i < n+1; ++i) cin >> a.at(i);
    int total = 0;
    rep(i,n+1) {
        total += abs(a.at(i+1) - a.at(i));   
    }

    vector<int> ans(n);
    rep(i,n) {
        if (
            (a.at(i) <= a.at(i+1) && a.at(i+1) <= a.at(i+2)) ||
            (a.at(i+2) <= a.at(i+1) && a.at(i+1) <= a.at(i))
        ) {
            ans.at(i) = total;
        }
        else {
            ans.at(i) = total - 2 * min(abs(a.at(i+1) - a.at(i)), abs(a.at(i+2) - a.at(i+1)));
        }
    }

    rep(i,n) cout << ans.at(i) << endl;
    return 0;
}