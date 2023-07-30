#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {

ll t;
cin>>t;

while(t--){
    ll n;
    cin>>n;
    ll *arr=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll grps=1;
    int flag=1;
    for(ll i=1;i<n;i++){
        
        if((arr[i]&arr[i-1])<=(arr[i]+arr[i-1])&&flag==1){
            arr[i]=arr[i]&arr[i-1];
            flag=1;
        }
        else{
            grps++;
        }
        if(arr[i]==0){
            flag=0;
        }
    }
    if(flag==0){
        grps--;
    }
    cout<<grps<<endl;
}

return 0;
}