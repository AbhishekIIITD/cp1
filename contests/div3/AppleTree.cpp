#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


ll ways(vector<int> *graph,int n,ll **dp,int x,int y){
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    else{
        ll ans=0;
        if(graph[x].size()==0&&graph[y].size()==0){
            ans= 1;
        }
        else if(graph[x].size()!=0){
            for(int i=0;i<graph[x].size();i++){
                ans= ans+ways(graph,n,dp,graph[x][i],y);

            }
        }
        else{
            for(int i=0;i<graph[y].size();i++){
                ans= ans+ways(graph,n,dp,x,graph[y][i]);

            }
        }
        dp[x][y]=ans;
        return dp[x][y];
    }
}
int main() {

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    vector<int> *graph=new vector<int>[n];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        graph[min(a,b)].push_back(max(a,b));
    }
    int q;
    cin>>q;
    ll **dp=new ll*[n];
    for(int i=0;i<n;i++){
        dp[i]=new ll[n];
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }


    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        cout<<ways(graph,n,dp,x-1,y-1)<<endl;
        
    }

}
return 0;
}