#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000007


int n,k,d;
ll dp[105][3];

int solve(int leftSum, bool state){
    if(leftSum>n)
    {
        return 0;
    } 
    if(leftSum==n){
        return state;
    }

    if(dp[leftSum][state]!=-1) {
        return dp[leftSum][state];
    }

    ll cnt= 0;

    for(int i=1;i<=k;i++){
        bool newState=state||(i>=d);
        cnt+= solve(leftSum+i, newState) % INF;
    }
        

    return dp[leftSum][state]= cnt%INF;

}

main(){
    for(int i=0;i<105;i++){
        for(int j=0;j<3;j++){
            dp[i][j]=-1;
        }
    }

    cin>>n>>k>>d;

    cout<<solve(0,0);
}