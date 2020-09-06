#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> board(h);
    for(int i = 0; i < h; ++i){
        cin >> board.at(i);
    }
    vector<vector<int>> dp(h,vector<int>(w));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            int n = 10000000;
            if(i == 0 && j == 0)
                n = board.at(0).at(0) == '#' ? 1 : 0;
            if(i > 0)
                n = min(n,
                dp.at(i-1).at(j) + (board.at(i-1).at(j) == '.' && board.at(i).at(j) == '#' ? 1 : 0));
            if(j > 0)
                n = min(n,
                dp.at(i).at(j-1) + (board.at(i).at(j-1) == '.' && board.at(i).at(j) == '#' ? 1: 0));
            dp.at(i).at(j) = n;
        }
    }
    cout << dp.at(h-1).at(w-1) << endl;
    return 0;
}