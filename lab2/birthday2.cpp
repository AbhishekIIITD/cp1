#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool compareGifts(pair<int,int> x,pair<int,int> y){
    return (x.second-x.first)<(y.second-y.first);
}

int main() {

int t;
cin>>t;

while(t--){
    int n,k;
    cin>>n>>k;
    
    pair<int,int> gifts[n];
    for(int i=0;i<n;i++){
        cin>>gifts[i].first;
        cin>>gifts[i].second;
    }
    sort(gifts,gifts+n,compareGifts);
    ll ans=0;
    
    for(int i=0;i<k;i++){
        ans+=gifts[i].second;
    }
    for(int i=k;i<n;i++){
        if(gifts[i].second<gifts[i].first){
            ans+=gifts[i].second;
        }
        else{
            ans+=gifts[i].first;
        }
    }
    cout<<ans<<endl;
}
return 0;
}