#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a.at(i);
    rep(i, m) cin >> b.at(i);

    int ai = 0;
    rep(i,n) {
        if(a.at(i) <= k) {
           ai++;
           k -= a.at(i); 
        }
        else break;
    }

    int bi = 0;
    rep(i, m) {
        if(b.at(i) <= k) {
            bi++;
            k -= b.at(i);
        }
        else break;
    }

    int ans = ai + bi;
    int ansi = ans;
    for(int i = ai-1; 0 <= i; i--) {
        k += a.at(i);
        ansi--;
        while(bi < m) {
            if(b.at(bi) <= k) {
                ansi++;
                k -= b.at(bi);
                bi++;
            }
            else break;
        }
        ans = max(ansi, ans);
    }
    cout << ans << endl;

    return 0;
}