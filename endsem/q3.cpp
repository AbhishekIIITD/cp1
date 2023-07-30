#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
t=1;
while(t--){
    ll n,m,k,r,g;
    cin>>n>>m>>k>>r>>g;
    ll *runes=new ll[k];
    ll *preRunes=new ll[k];
    ll last=0;
    for(int i=0;i<k;i++){
        cin>>runes[i];
        preRunes[i]=runes[i]+last;
        last+=runes[i];
    }
    vector<vector<ll>> bridges(m,vector<ll>(4,0));
    ll goldReq=0;
    ll maxLev=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<4;j++){
            cin>>bridges[i][j];

        }
        goldReq+=bridges[i][2];
        maxLev=max(maxLev,bridges[i][3]);
    }
    if(goldReq<=g&&maxLev<k&&preRunes[maxLev]<=r){
        cout<<preRunes[maxLev]<<endl;
    }
    else{
        cout<<-1<<endl;
    }

}
return 0;
}