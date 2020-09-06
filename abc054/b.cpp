#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    rep(i,n) cin >> a.at(i);
    rep(i,m) cin >> b.at(i);

    for(int i = 0; i <= n-m; i++) {
        bool found = true;
        size_t pos = a.at(i).find(b.at(0));
        while(pos != string::npos && pos >= 0) {
            for(int j = 1; j < m; j++) {
                string asub = a.at(i+j).substr(pos, b.at(j).size());
                if(asub != b.at(j)) {
                    found = false;
                    break;
                }
            }
            if(found) {
                cout << "Yes" << endl;
                return 0;
            }
            else {
                pos = a.at(i).find(b.at(0), pos + b.at(0).size());
            }
        }
    }

    cout << "No" << endl;
    return 0;
}