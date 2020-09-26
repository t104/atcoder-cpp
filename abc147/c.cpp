#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;

bool trust(int flag, int index) {
    return (flag >> index) & 1;
}

int count (int flag) {
    int dst = 0;
    rep(i, n) if (trust(flag, i)) dst++;
    return dst;
}

int main() {
    cin >> n;
    vector<vector<P>> evidence(n);


    rep(i, n) {
        int a;
        cin >> a;
        evidence.at(i).resize(a);
        rep(j, a) {
            cin >> evidence.at(i).at(j).first >> evidence.at(i).at(j).second;
        }
    }
    int ans = 0;
    for (int flag = 0; flag <= 1<<n; flag++) {
        bool ok = true;
        rep(i, n) {
            if (trust(flag, i)) {
                for (P p : evidence.at(i)) {
                    if (trust(flag, p.first) != p.second) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        ans = max(ans, count(flag));
    }
    cout << ans << endl;
    return 0;
}