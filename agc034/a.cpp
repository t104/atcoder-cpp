#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--; b--; c--; d--;

    bool ok = true;
    string ac = s.substr(a, c-a+1);
    string bd = s.substr(b, d-b+1);
    if (ac.find("##") != string::npos) ok = false;
    if (bd.find("##") != string::npos) ok = false;
    if (d < c) {
        string _bd_ = s.substr(b-1, d-b+3);
        if (_bd_.find("...") == string::npos) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}