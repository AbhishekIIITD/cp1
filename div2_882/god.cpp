#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mini(ll a,ll b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
ll solve(ll *arr,ll **dp,ll n,ll k){
    if(k==0&&n==0){
        return 0;
    }
    else if(k==0||n==0){
        return dp[n][k]=INT_MAX;
    }
    else if(dp[n][k]!=-1){
        return dp[n][k];
    }
    else{
        int sum=0;
        dp[n][k]=INT_MAX;
        for(int i=0;i<n;i++){
            if(i==0){
                dp[n][k]=solve(arr+1,dp,n-1,k-1);

            }
            else{
                sum=sum+abs(arr[i]-arr[i-1]);
                dp[n][k]=mini(solve(arr+i+1,dp,n-i-1,k-1)+sum,dp[n][k]);
            }
        }
        return dp[n][k];
    }
}
int main() {

ll t;
cin>>t;

while(t--){
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    ll **dp=new ll*[n+1];
    for(ll i=0;i<=n;i++){
        dp[i]=new ll[k+1];
        for(ll j=0;j<=k;j++){
            dp[i][j]=-1;
        }
    }
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,dp,n,k)<<endl;


    
}
return 0;
}