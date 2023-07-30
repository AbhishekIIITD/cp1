#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(vector<vector<int>> &graph,int *dp,int *visited,int si,int ei){
    cout<<si<<" "<<ei<<endl;
    if(si==ei){
        dp[si]=1;

        return dp[si]=1;
    }
    else if(dp[si]!=0&&dp[si]!=-1){

        return dp[si];
    }
    else{

        int ans=-1;
        for(int i=0;i<graph[si].size();i++){
            int smallAns=-1;
            if(visited[graph[si][i]]==-1){
                visited[i]=si;
                smallAns=solve(graph,dp,visited,graph[si][i],ei);
            }
            else if(i!=visited[si]){
                visited[i]=-1;
            }
            
            if(smallAns!=-1){
                ans=max(ans,smallAns+1);
                
                
            }
        }
        return dp[si]=ans;

    }
    
}
int main() {

int t;
t=1;
while(t--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++){
        int si,ei;
        cin>>si>>ei;
        graph[si-1].push_back(ei-1);
        graph[ei-1].push_back(si-1);

    }
    int *visited=new int[n];
    int *dp=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=-1;
        dp[i]=0;
    }
    visited[0]=0;

    int ans=solve(graph,dp,visited,0,n-1);
    if(ans==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<ans<<endl;
    }



}
return 0;
}