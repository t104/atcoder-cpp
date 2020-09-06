#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

struct train {
    int station;
    int start;
    int interval;
    int duration;
};

int main() {
    int n;
    cin >> n;
    vector<train> trains(n-1);
    rep(i,n-1) {
        trains.at(i).station = i;
        cin >> trains.at(i).duration;
        cin >> trains.at(i).start;
        cin >> trains.at(i).interval;
    }

    rep(i,n) {
        if (i == n-1) {
            cout << 0 << endl;
            continue;
        }
        int time = 0;
        for (int j = i; j < n-1; ++j) {
            int start = trains.at(j).start;
            int interval = trains.at(j).interval;
            int duration = trains.at(j).duration;
            time = max(time, start);
            if ((time - start) % interval != 0) {
                time = start + ((time - start)/interval + 1) * interval;
            }
            time += duration;
        }
        cout << time << endl;
    }
    return 0;
}