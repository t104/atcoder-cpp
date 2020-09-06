#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll x, k, d;
    cin >> x >> k >> d;
    if (x < 0) x = - x;
    
    ll q = x/d;
    if (k <= q) {
        x -= d * k;
        cout << x << endl;
        return 0;
    }
    x -= q * d;
    if ((k-q)%2 == 0) {
        cout << x << endl;
    }
    else {
        cout << abs(x-d) << endl;
    }
    return 0;
}