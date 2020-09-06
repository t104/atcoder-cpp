#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int ans = 1001001001;
    for(int i = 0; i+2 < s.size(); i++) {
        string t = s.substr(i, 3);
        ans = min(ans, abs(753-stoi(t)));
    }
    cout << ans << endl;
    return 0;
}