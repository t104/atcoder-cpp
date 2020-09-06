#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    
    set<int> fav;
    rep(i, m) fav.insert(i);

    rep(i, n) {
        int k;
        cin >> k;
        set<int> next;
        rep(j, k) {
            int a;
            cin >> a;
            a--;
            if(fav.count(a)) next.insert(a);
        }
        fav = next;
    }

    cout << fav.size() << endl;

    return 0;
}