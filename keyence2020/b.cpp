#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<P> robots(n);
    rep(i,n) {
        int x, l;
        cin >> x >> l;
        robots.at(i).second = x-l;
        robots.at(i).first = x+l;
    }
    sort(robots.begin(), robots.end());
    int r = -2e9;
    int count = 0;
    rep(i,n) {
        if (r <= robots.at(i).second) {
            count++;
            r = max(r, robots.at(i).first);
        }
    }
    cout << count << endl;
    return 0;
}