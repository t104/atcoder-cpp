#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    priority_queue<int> pq;

    int h1 = 0;
    int count = 0;
    rep(i, n) {
        int h2;
        cin >> h2;
        if(h2 > h1) {
            pq.push(count);
            count = 0;
        }
        else {
            count++;
        }
        h1 = h2;
    }
    pq.push(count);

    cout << pq.top() << endl;

    return 0;
}