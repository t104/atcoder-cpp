#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const ll MAX_X = pow(10, 9);

int main() {
    ll x = 0;
    for(int i = -10; i < 11; i++) {
        cout << i << " " << pow(i, 5) - pow(i-1, 5) << endl;
    }
    return 0;
}
