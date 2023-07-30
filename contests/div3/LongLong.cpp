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
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    ll sum=0;
    ll grps=0;
    ll flag=0;
    for(ll i=0;i<n;i++){
        if(arr[i]>0){
            sum+=arr[i];
            flag=0;
        }
        else{
            if(flag==0&&arr[i]!=0){
                flag=1;
                grps++;
            }
            sum=sum+(-1*arr[i]);
        }
    }
    cout<<sum<<" "<<grps<<endl;

}
return 0;
}