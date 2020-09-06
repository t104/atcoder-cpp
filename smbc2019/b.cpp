#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const double rate = 1.08;

int main() {
    int n;
    cin >> n;
    int q = n / rate;
    int p = 0;
    while (p < n) {
        p = q * rate;
        if(p == n) {
            cout << q << endl;
            return 0;
        }
        q++;
    }
    cout << ":(" << endl;
    return 0;
}