#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
const ll LINF = 1LL<<60;

int main() {
    int n;
    cin >> n;
    list<int> p(n);
    for (auto itr = p.begin(); itr != p.end(); ++itr) {
        cin >> *itr;
        (*itr)--;
    }
    vector<bool> use(n, false);
    vector<int> ans;
    for (auto itr = p.begin(); itr != p.end(); ++itr) {
        int idx = distance(p.begin(), itr);
        if (*itr == idx) continue;
        for (auto j = itr; j != p.end(); ++j) {
            int idxj = distance(p.begin(), j);

            if(*j == idx) {
                int x = *j;
                p.erase(j);
                p.insert(itr, x);
                for (int k = idxj-1; idx <= k ; --k) {
                    if (use.at(idxj)) {
                        cout << -1 << endl;
                        return 0;
                    }
                    use.at(idxj) = true;
                    ans.push_back(k);
                }
            }
        }
    }

    if (ans.size() == n-1) {
        rep(i,n-1) {
            cout << ans.at(i) + 1 << endl;
        }
        return 0;
    }

    cout << -1 << endl;
    return 0;
}