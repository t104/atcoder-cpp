#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string n;
    cin >> n;
    int r = 0;
    for (auto c : n) {
        r += c - '0';
        r %= 9;
    }
    if (r == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}