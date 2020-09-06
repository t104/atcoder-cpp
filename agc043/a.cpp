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
    
    int black_min = 1000000;
    vector<int> route(h+w-2,1);
    for(int i = 0; i < h-1; ++i) route.at(i) = 0;
    do{
        int x,y,black;
        x = 0; y = 0; black = 0;
        if(board.at(x).at(y) == '#') ++black;
        for(int i: route){
            if(i == 0) ++x;
            else ++y;
            if(board.at(x).at(y) == '#'){
                ++black;
                if(black_min <= black) break;
            }
        }
        black_min = min(black_min, black);
    } while (next_permutation(route.begin(), route.end()));
    cout << black_min << endl;
    return 0;
}