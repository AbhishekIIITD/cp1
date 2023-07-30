#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
unordered_map<char,vector<int>> Occurences;


int solve(int m,char* l,char* r,int last,vector<vector<int>> &dp){
    if(dp[m][last]!=-1){
        return dp[m][last];
    };
    if(m==1){
        char low=l[0];
        char high=r[0];
        while(low<=high){
            auto itr=upper_bound(Occurences[low].begin(),Occurences[low].end(),last);
            if(Occurences[low].size()==0||itr==Occurences[low].end()){
                // cout<<*itr<<endl;
                return dp[m][last]=1;
            }
            low++;
            
            
        }
        return dp[m][last]=0;
    }
    else{
        int ans=0;
        char low=l[0];
        char high=r[0];
        while(low<=high){
            if(Occurences[low].empty()){
                return dp[m][last]=1;
            }
            auto itr=upper_bound(Occurences[low].begin(),Occurences[low].end(),last);
            if(Occurences[low].end()==itr){
                return dp[m][last]=1;
            }

            ans=ans||solve(m-1,l+1,r+1,*itr,dp);
            if(ans==1){
                break;
            }
            low++;
        }
        return dp[m][last]=ans;
    }
}
int main() {

int t;
cin>>t;

while(t--){
    
    string s;
    cin>>s;
    
    for(int i=0;i<s.size();i++){
        Occurences[s[i]].push_back(i+1);
    }
    int m;
    cin>>m;
    vector<vector<int>> dp(m+1,vector<int>(s.size()+2,-1));
    char l[m],r[m];

    for(int i=0;i<m;i++){
        cin>>l[i];
    }
    for(int i=0;i<m;i++){
        cin>>r[i];
    }
    if(solve(m,l,r,0,dp)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    Occurences.clear();

}
return 0;
}