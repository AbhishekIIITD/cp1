#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

ll t;
cin>>t;

while(t--){
    ll n;
    cin>>n;
    pair<ll,ll> vertices[n];
    map<ll,ll> hashV;
    map<ll,ll> hashH;
    map<ll,ll> PosSlope;
    map<ll,ll> negSlope;
    for(ll i=0;i<n;i++){
        cin>>vertices[i].first>>vertices[i].second;
        hashV[vertices[i].first]++;
        hashH[vertices[i].second]++;
        PosSlope[vertices[i].first-vertices[i].second]++;
        negSlope[vertices[i].first+vertices[i].second]++;

    }
    ll ans=0;
    
    for(ll i=0;i<n;i++){
        ans+=hashV[vertices[i].first]-1;
        ans+=hashH[vertices[i].second]-1;
        ans+=PosSlope[vertices[i].first-vertices[i].second]-1;
        ans+=negSlope[vertices[i].first+vertices[i].second]-1;
        hashV[vertices[i].first]--;
        hashH[vertices[i].second]--;
        PosSlope[vertices[i].first-vertices[i].second]--;
        negSlope[vertices[i].first+vertices[i].second]--;
    }
    cout<<ans*2<<endl;
    

}
return 0;
}