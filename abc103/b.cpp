#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s, t;
    cin >> s >> t;

    if(s.size() != t.size()) {
        cout << "No" << endl;
        return 0;
    }

    int n = s.size();
    rep(i, n) {
        string u = t.substr(i, n-i) + t.substr(0, i);
        if(s == u) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}