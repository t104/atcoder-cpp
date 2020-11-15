#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;

struct hito {
    int start, end, p;
    hito(){
        start = 0, end = 0, p = 0;
    }
    hito(int start, int end, int p) : start(start), end(end), p(p) {}
};

int main() {
    int n;
    ll w;
    cin >> n >> w;
    vector<hito> a(n), b(n);
    rep(i,n) {
        int s, t, p;
        cin >> s >> t >> p;
        a.at(i) = hito(s, t, p);
        b.at(i) = a.at(i);
    }
    sort(a.begin(), a.end(), [&](hito x, hito y) {
        return x.start < y.start;
    });
    sort(b.begin(), b.end(), [&](hito x, hito y) {
        return x.end < y.end;
    });


    ll now = 0;
    int j = 0;
    rep(i,n) {
        now += a.at(i).p;
        for (int k = j; k < n; ++k) {
            if (b.at(k).end <= a.at(i).start) {
                now -= b.at(k).p;
                j = k+1;
            }
            else break;
        }
        if (w < now) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}