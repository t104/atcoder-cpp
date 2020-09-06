#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int MAX_N = 200005;
int n;
ll k;
vector<int> memo(MAX_N);

int main() {
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
        a.at(i)--;
    }
    
    int p = 0, first = 0, second = 0;
    map<int, int> m;

    for(ll i = 0; i < k; i++) {
        if(m.count(p)) {
            first = m[p];
            second = i;
            break;
        }
        m[p] = i;
        memo.at(i) = p;
        
        if(i == k - 1) {
            cout << p + 1 << endl;
            return 0;
        }
        p = a.at(p);
    }

    k -= first;
    k %= second - first;
    k += first;
    cout << memo.at(k) + 1 << endl;

    return 0;
}