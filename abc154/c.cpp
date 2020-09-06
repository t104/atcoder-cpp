#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, size1,size2;
    string ans;
    vector<int> vt;
    cin >> n;
    rep(i,n) {
        int m;
        cin >> m;
        vt.push_back(m);
    }
    size1 = vt.size();
    sort(vt.begin(), vt.end());
    vt.erase(unique(vt.begin(), vt.end()), vt.end());
    size2 = vt.size();
    if(size1 == size2) ans = "YES";
    else ans = "NO";
    cout << ans << endl;
    return 0;
}