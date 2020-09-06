#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    const int inf = 1 << 30;
    vector<int> dp1(n+1, -inf), dp2(n+1, -inf);
    dp1.at(0) = 0;
    dp2.at(0) = 0;

    for (int i = 1; i < n+1; ++i) {
        dp1.at(i) = dp2.at(i-1) + 1;
        if (2 <= i && s.at(i-1) != s.at(i-2)) {
            dp1.at(i) = max(dp1.at(i), dp1.at(i-1) + 1);
        }
        
        if (2 <= i) {
            dp2.at(i) = dp1.at(i-2) + 1;
            if (4 <= i && (s.at(i-4) != s.at(i-2) || s.at(i-3) != s.at(i-1))) {
                dp2.at(i) = max(dp2.at(i), dp2.at(i-2) + 1);
            }
        }
    }

    cout << max(dp1.at(n), dp2.at(n)) << endl;
    return 0;
}