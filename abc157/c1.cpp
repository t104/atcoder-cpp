#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>


using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> vt(N,-1);
    bool flag=true;
    for(int i=0; i<M; i++){
        int s,c;
        cin >> s >> c;
        if(vt[s-1]==-1) vt[s-1]=c;
        else if(vt[s-1]!=c){
            flag=false;
        }
    }

    if(vt[0]==0 && N!=1) flag=false;

    if(N==1 && flag==true && M!=0) cout << vt[0] << endl;
    else if(N==1 && flag==true) cout << 0 << endl;
    else if(flag){
        for(int i=0; i<N; i++){
            if(vt[i]==-1 && i==0) cout << 1;
            else if(vt[i]==-1) cout << 0;
            else{
                cout << vt[i];
            }
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }


    return 0;
}
