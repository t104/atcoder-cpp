#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int max_size = 200005;
int n;
bitset<max_size> bs;

int popcount(int n) {
    int count = 0;
    int i = 0;
    for (int j = 1; j <= n; j*=2) {
        if (n>>i&1) count++;
        ++i;
    }
    return count;
}

int residue(int mod, vector<int> &res) {
    int ri = 1, r = 0;
    rep(i,n) {
        res.at(i) = ri;
        if (bs.test(i)) {
            r += ri;
            r %= mod;
        }
        ri <<= 1;
        ri %= mod;
    }
    return r;
}

int main() {
    cin >> n;
    string s;
    cin >> s;
    bs = bitset<max_size>(s);
    int mod = bs.count();
    vector<int> ans(n);
    vector<int> resn1(n), resp1(n);
    int rn1 = 0;
    if (0 < mod-1) rn1 = residue(mod-1, resn1);
    int rp1 = residue(mod+1, resp1);

    rep(i,n) {
        int m, r;
        if (bs.test(i)) {
            m = mod-1;
            if (m == 0) {
                ans.at(i) = 0;
                continue;
            }
            r = rn1;
            r -= resn1.at(i);
        }
        else {
            m = mod+1;
            r = rp1;
            r += resp1.at(i);
        }
        r %= m;
        if (r<0) r += m;
        int count = 1;
        while (r != 0) {
            r %= popcount(r);
            count++;
        }
        ans.at(i) = count;
    }

    reverse(ans.begin(), ans.end());
    rep(i,n) cout << ans.at(i) << endl;
    return 0;
}