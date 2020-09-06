#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int MAX_N = 100100100;

int main() {
    ll x;
    cin >> x;
    ll money = 100;
    int ans = 0;
    for(int i = 1; i < MAX_N; i++) {
        money *= 1.01;
        if(x <= money) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}