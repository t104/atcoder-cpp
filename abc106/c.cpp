#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll days = 5e15;

int main() {
    string s;
    ll k;
    cin >> s >> k;
    for (char c : s) {
        int d = c - '0';
        if (d == 1) k--;
        else {
            k = 0;
        }
        if (k <= 0) {
            cout << c << endl;
            return 0;
        }
    }

    return 0;
}