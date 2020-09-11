#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    vector<int> ans(n);
    rep(i,n){
        if (0 < k) {
            ans.at(i) = s;
            k--;
        }
        else {
            if (s == 1e9) ans.at(i) = s-1;
            else ans.at(i) = s + 1;
        }
    }
    
    rep(i,n) {
        cout << ans.at(i);
        if (i < n-1) cout << ' ';
    }
    cout << endl;
    return 0;
}