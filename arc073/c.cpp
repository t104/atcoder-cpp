#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> tn(n);
    rep(i,n) cin >> tn.at(i);
    
    int ans = 0;
    int end = 0;
    rep(i,n) {
        if(tn.at(i) < end) {
            ans += tn.at(i) + t - end;
        }
        else ans += t;
        end = tn.at(i) + t;
    }

    cout << ans << endl;

    return 0;
}