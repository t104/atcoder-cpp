#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h.at(i);
    
    int count = 0, sum = 0;
    do {
        sum = 0;
        int prev = 0;
        rep(i,n) {
            if (0 < h.at(i)) {
                if (prev == 0) count++;
                prev = h.at(i);
                h.at(i)--;
                sum += h.at(i);
            }
            else prev = 0;
        }
    } while (sum != 0);
    cout << count << endl;
    return 0;
}