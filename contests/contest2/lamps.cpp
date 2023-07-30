
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll compare(pair<ll,ll> x,pair<ll,ll> y){
    if(x.first<y.first){
        return 1;
    }
    else if(x.first>y.first){
        return 0;
    }
    else{
        if(x.second>y.second){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int main() {
 
    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> lamps;
        for(ll i=0;i<n;i++){
            pair<ll,ll> x;
            cin>>x.first>>x.second;

            lamps.push_back(x);
        }
        sort(lamps.begin(),lamps.end(),compare);
        ll ans=0;
        ll currAi=0;
        ll lampsOn=0;

        for(int i=0;i<n;i++){
            if(lampsOn<lamps[i].first){
                ans+=lamps[i].second;
                lampsOn++;
            }
            if(currAi<lamps[i].first){
                currAi=lamps[i].first;
                lampsOn=1;
            }
            
            

        }
        cout<<ans<<endl;
    }
    return 0;
}