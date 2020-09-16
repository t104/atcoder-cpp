#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s;
    int q;
    cin >> s >> q;
    
    bool r = false;
    rep(i, q) {
        int query;
        cin >> query;
        if (query == 1) r = !r;
        if (query == 2) {
            int f;
            string c;
            cin >> f >> c;
            if ((!r && f == 1) || (r && f == 2)) s.insert(0, c);
            if ((r && f == 1) || (!r && f == 2)) s += c;
        }
    }

    if (r) reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}