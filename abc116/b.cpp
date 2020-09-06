#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int s;
    cin >> s;
    
    map<int, int> mp;
    mp[s] = 1;

    for(int i = 2;i < 1000005; i++) {
        if(s % 2 == 0) s /= 2;
        else s = 3 * s + 1;
        if(mp.count(s)) {
            cout << i << endl;
            return 0;
        }
        else {
            mp[s] = i;
        }
    }
    return 0;
}