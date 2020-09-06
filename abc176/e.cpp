#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> h(M), w(M);
    set<P> points;
    rep(i,M) {
        cin >> h.at(i) >> w.at(i);
        points.insert({ h.at(i), w.at(i) });
    }
    map<int,int> hCount, wCount;
    rep(i,M) {
        hCount[h.at(i)]++;
        wCount[w.at(i)]++;
    }

    int hMax = 0, wMax = 0;
    vector<int> hm, wm;
    for (auto hc : hCount) {
        if (hMax < hc.second) {
            hm.clear();
            hm.push_back(hc.first);
        }
        if (hMax == hc.second) hm.push_back(hc.first);
        hMax = max(hMax, hc.second);
    }
    for (auto wc : wCount) {
        if (wMax < wc.second) {
            wm.clear();
            wm.push_back(wc.first);
        }
        if (wMax == wc.second) wm.push_back(wc.first);
        wMax = max(wMax, wc.second);
    }
    int ans = hMax + wMax - 1;
    for (auto hi : hm) {
        for (auto wi : wm) {
            if (points.find({ hi, wi }) == points.end()) {
                cout << ans + 1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}