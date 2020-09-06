#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    ll ans = 0;
    for(int i=0; i < (1<<(s.size()-1)); i++){
        ll n = 0;
        rep(j,s.size()){
            n += s[j] - '0';
            if(i & (1<<j) || j == s.size()-1) {
                ans += n;
                n = 0;
            }
            else n *= 10;
        }
    }
    cout << ans << endl;
    return 0;
}