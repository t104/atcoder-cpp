#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }

    vector<int> order(n + 1, -1);
    vector<int> city;
    int c = 1, l = 0;
    {
        int p = 1;
        while(order.at(p) == -1) {
            order.at(p) = city.size();
            city.push_back(p);
            p = a.at(p-1);
        } 
        c = city.size() - order.at(p);
        l = order.at(p);
    }

    if(k < l) cout << city.at(k) << endl;
    else {
        k -= l;
        k %= c;
        cout << city.at(l + k) << endl;
    }

    return 0;
}