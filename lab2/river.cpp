#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
int main() {

ll t;
t=1;
while(t--){
    ll n,m;
    cin>>n>>m;
    
    ll **dp=new ll*[n+1];
    for(ll i=0;i<=n;i++){
        dp[i]=new ll[m+1];
        for(ll j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    ll *arr=new ll[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    
    
    for(ll i=0;i<=n;i++){
        dp[i][0]=1;
    }
    
    ll *pre=new ll[m+1];
    for(ll i=0;i<=m;i++){
        pre[i]=1;
    }
    
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            
            if(arr[i-1]>=j){
                dp[i][j]=((dp[i][j])%(mod)+(pre[j])%(mod))%(mod);
            }
            else{
                dp[i][j]=((dp[i][j])%(mod)+(pre[j]-pre[j-arr[i-1]-1])%(mod))%(mod);
            }
        }
        pre[0]=dp[i][0];
        for(ll k=1;k<=m;k++){
            pre[k]=(dp[i][k]+pre[k-1]);
        }
    }
    cout<<dp[n][m]<<endl;
    
    


}
return 0;
}