#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    priority_queue<int> b;
    rep(i,n) {
        int bi;
        cin >> a.at(i) >> bi;
        b.push(bi);
    }
    
    int amax = *max_element(a.begin(), a.end());
    int ans = 0;
    while (0 < h) {
        if (b.size() && amax < b.top()) {
            h -= b.top();
            b.pop();
            ans++;
        }
        else {
            ans += h/amax;
            if (0 < (h % amax)) ans++;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}