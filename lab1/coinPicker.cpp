#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;



int main() {
    ll n,k;
    cin>>n>>k;
    pair<ll,ll> arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i].first;

    }
    for(ll i=0;i<n;i++){
        cin>>arr[i].second;

    }
    ll i,j;
    i=0;j=0;
    ll minSum=-1;
    ll currCost=0;
    ll currVal=0;
    while(j<n){
        
        if(currVal<k){
            currVal+=arr[j].first;
            currCost+=arr[j].second;
            j++;
        }
        else{
            
            currVal-=arr[i].first;
            currCost-=arr[i].second;
            i++;
        }

        if(currVal>=k){
            if(minSum==-1){
                minSum=currCost;
            }
            else{
                minSum=min(currCost,minSum);
            }
        }
        
    }
   
    cout<<minSum<<endl;


return 0;
}
