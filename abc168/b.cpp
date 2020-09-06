#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    int k;
    cin >> k >> s;
    if(s.size() <= k) {
        cout << s << endl;
    } else {
        string ans = s.substr(0, k);
        ans += "...";
        cout << ans << endl;
    }
    return 0;
}