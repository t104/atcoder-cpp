#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string a, b;
    cin >> a >> b;
    int n = stoi(a + b);
    rep(i, 10000) {
        if(n == pow(i, 2)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}