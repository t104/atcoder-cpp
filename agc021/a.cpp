#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    bool nine = false;
    if (s.size() == 1) sum += s.at(0) - '0';
    for (int i = 1; i < s.size(); i++) {
        int d1 = s.at(i) - '0';
        int d0 = s.at(i-1) - '0';
        if (d1 != 9) {
            sum += d0 - 1;
            sum += 9 * (s.size() - i);
            break;
        }
        sum += d0;
        if (i == s.size()-1) sum += d1;
    }
    cout << sum << endl;
    return 0;
}