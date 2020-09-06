#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    int n;
    cin >> n;

    ll ans = 0;
    vector<int> f(n+1);
    for(int i = 1; i <= n; ++i) {
        int j = i;
        while(j <= n) {
            ++f.at(j);
            j += i;
        }
    }

    for(int i = 1; i <= n; ++i) {
        ans += (ll)i * f.at(i);
    }
    cout << ans << endl;
    return 0;
}