#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);

    ll ans = 0;
    rep(i, n-1) {
        for(int j = i+1; j < n; j++) {
            if(a.at(i) > a.at(j)) ans++;
        }
    }

    int ansi = 0;
    sort(a.begin(), a.end());
    rep(i,n) {
        int dup = 1;
        while(i < n-1 && a.at(i) == a.at(i+1)) {
            dup++; i++;
        }
        ansi += dup * (n-i-1);
    }
    
    ans *= k;
    ans %= mod;
    ll ansn = ((ll)k * (k-1))/2;
    ansn %= mod;
    ansn *= ansi;
    ansn %= mod;
    ans += ansn;
    ans %= mod;
    cout << ans << endl;

    return 0;
}