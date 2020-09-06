#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll a, b;
    cin >> a >> b;
    if(a == 0 || b == 0 || (a < 0 && 0 < b)) {
        cout << "Zero" << endl;
        return 0;
    }
    if(b < 0 && (b-a)%2 == 0) {
        cout << "Negative" << endl;
    }
    else {
        cout << "Positive" << endl;
    }

    return 0;
}