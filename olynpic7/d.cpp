#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main() {
    int n, m;
    cin >> m;
    vector<int> sx(m), sy(m);
    rep(i,m) cin >> sx[i] >> sy[i];
    cin >> n;
    vector<int> px(n), py(n);
    rep(i,n) cin >> px[i] >> py[i];

    vector<int> dx(m-1), dy(m-1);
    rep(i,m-1) {
        dx[i] = sx[i+1] - sx[i];
        dy[i] = sy[i+1] - sy[i];
    }

    set<P> photo;
    rep(i,n) photo.insert({px[i], py[i]});


    int p;
    rep(i,n) {
        int x = px[i];
        int y = py[i];
        bool ok = true;
        rep(j,m) {
            x += dx[j];
            y += dy[j];
            if (!photo.count({x, y})) ok = false;
        }
        if (ok) {
            p = i;
            break;
        }
    }

    cout << px[p] - sx[0] << ' ';
    cout << py[p] - sy[0] << endl;
    return 0;
}