#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {

int t;
cin>>t;

while(t--){
    ll n,k,q;
    cin>>n>>k>>q;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll i=0;
    ll j=0;
    ll currSum=0;
    ll ans=0;
    while(j<n){
        if(arr[j]<=q){
            if((j-i+1)>=k){
                ll x=(j-i+1);
                ll y=k-1;
                currSum=(x*(x+1)/2)-(y/2)*(x+x-1);
                j++;

            }
            else{
                j++;
            }

        }
        else{
            ans+=currSum;
            currSum=0;
            i=j+1;
            j++;

        }
    }
    ans+=currSum;
    cout<<ans<<endl;

    
}
return 0;
}