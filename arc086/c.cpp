#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using M = map<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    M mp;
    rep(i,n) {
        int ai;
        cin >> ai;
        if (mp.count(ai)) mp.at(ai)++;
        else mp[ai] = 1;
    }
    int m = mp.size();
    if (m <= k) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a;
    for(auto mi : mp) {
        a.push_back(mi.second);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    rep(i, m-k) {
        ans += a.at(i);
    }
    cout << ans << endl;
    
    return 0;
}