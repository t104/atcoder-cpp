#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

using P = pair<int,int>;

const int DIM = 2;

int main() {
    int n,x,y;
    cin >> n >> x >> y;
    int g[n][DIM];
    rep(i,n-1){
        g[i][0] = i+1;
        g[i][1] = -1;
    }
    rep(i,DIM) g[n-1][i] = -1;
    g[x-1][1] = y-1;

    queue<int> current;
    rep(i,n) current.push(i);
    for(int k = 0; k < n-1; ++k){
        queue<int> next;
        while(!current.empty()){
            int p = current.front();
            // cout << p << ' ';
            rep(i,DIM){
                int q = g[p][i];
                if(q > -1 && !(q == y-1 && i == 0 && k+1 >= y-x)) next.push(q);
            }
            current.pop();
        }
        // cout << endl;
        cout << next.size() << endl;
        current = next;
    }
    return 0;
}