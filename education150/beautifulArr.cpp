#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;

while(t--){
    ll q;
    cin>>q;
    ll arr[q];
    string ans="";
    ll first=-1;
    ll last=-1;
    ll flag=0;
    for(ll i=0;i<q;i++){
        if(i==0){
            cin>>arr[i];
            ans+='1';
            first=arr[i];
            last=arr[i];

        }
        else{
            cin>>arr[i];
            if(arr[i]>=last&&flag==0){
                ans+='1';
                last=arr[i];
            }
            else if(arr[i]<last&&flag==0&&arr[i]<=first){
                flag=1;
                ans+='1';
                last=arr[i];
            }
            else if(arr[i]>=last&&arr[i]<=first){
                ans+='1';
                last=arr[i];

            }
            else{
                ans+='0';
            }
        }
        
    }
    cout<<ans<<endl;

}
return 0;
}