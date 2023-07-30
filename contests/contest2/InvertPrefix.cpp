#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;

while(t--){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans[n];
    ll j=0;
    ll i=0;
    while(i<n){
        if(arr[i]==0){
            ans[j]=i-j;
            j++;
            ll x=i-j+1;
            while(x>0){
                ans[j++]=0;
                x--;
            }

        }
        i++;
    }
    
    if(j==n){
        cout<<"YES"<<endl;
        for(ll i=n-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


}
return 0;
}