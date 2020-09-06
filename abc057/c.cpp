#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int calc_digit(ll n) {
    int res = 0;
    while(0 < n) {
        n /= 10;
        res++;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    int res = (1<<29);

    for(ll i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            int digit = max(calc_digit(i),calc_digit(n/i));
            res = min(res, digit);
        }
    }
    cout << res << endl;

    return 0;
}