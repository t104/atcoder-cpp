#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    string former = s.substr(0, a);
    string latter = s.substr(a+1, b);
    bool ok = true;
    ok = ok && s.at(a) == '-';

    for(char c : former) {
        ok = ok && '0' <= c && c <= '9';
    }

    for(char c : latter) {
        ok = ok && '0' <= c && c <= '9';
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}