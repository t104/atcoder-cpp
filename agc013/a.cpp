#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    int state = 0, count = 0;
    rep(i,n-1) {
        if (a.at(i) < a.at(i+1)) {
            if (state == -1) {
                count++;
                state = 0;
            }
            else state = 1;
        }
        if (a.at(i) > a.at(i+1)) {
            if (state == 1) {
                count++;
                state = 0;
            }
            else state = -1;
        }
    }
    cout << count + 1 << endl;
    return 0;
}