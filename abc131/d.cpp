#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<P> jobs(n);
    rep(i,n) {
        cin >> jobs.at(i).second >> jobs.at(i).first;
    }
    sort(jobs.begin(), jobs.end());
    ll time = 0;
    rep(i,n) {
        time += jobs.at(i).second;
        if (jobs.at(i).first < time) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}