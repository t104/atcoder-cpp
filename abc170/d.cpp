#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i < n-1 && a.at(i) == a.at(i+1)) continue;
        bool ok = true;
        for(int j = 0; j < i; j++) {
            if((a.at(i) % a.at(j)) == 0) {
                ok = false;
                break;
            }
        }
        if(ok) ans++;
    }
    cout << ans << endl;
    return 0;
}
