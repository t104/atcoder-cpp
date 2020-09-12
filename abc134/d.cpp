#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a.at(i);
    
    vector<int> box(n+1);
    for (int i = n; 0 < i; --i) {
        int sum = 0;
        for (int j = i; j <= n; j += i) {
            sum += box.at(j);
        }
        sum %= 2;
        box.at(i) = (sum + a.at(i)) % 2;
    }

    int m = 0;
    vector<int> b;
    for (int i = 1; i <= n; ++i) {
        m += box.at(i);
        if (box.at(i) == 1) b.push_back(i);
    }

    int x = b.size();
    cout << m << endl;
    rep(i,x) {
        cout << b.at(i);
        if (i < x-1) cout << ' ';
    }
    if (0 < x) cout << endl;
    return 0;
}