#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int moves(int x,int y){
    int ans=0;
    while(x<y){
        if(y>2*x){
            ans++;
            x=2*x;

        }
        else{
            ans++;
            break;
        }
    }
    return ans;
}
void solve(int n,int k,int *target,int *gems){
    if(k>1000){
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=gems[i];
        }
        cout<<ans<<endl;
        return;
    }

    int **dp=new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i]=new int[k+1];
        for(int j=0;j<=k;j++){
            dp[i][j]=0;
        }

    }
    for(int i=1;i<=n;i++){
        if(target[i-1]==1){
            dp[i][0]=gems[i-1];
        }
        dp[i][0]+=dp[i-1][0];
    }
    for(int i=1;i<=n;i++){
        int m=moves(1,target[i-1]);
        for(int j=1;j<=k;j++){
            
            if(m<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-m]+gems[i-1]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k]<<endl;

}
int main() {

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int target[n];
    int gems[n];
    for(int i=0;i<n;i++){
        cin>>target[i];
    }
    for(int i=0;i<n;i++){
        cin>>gems[i];

    }
    solve(n,k,target,gems);

}
return 0;
}