#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
template <class T>
T max(T& t1, T& t2)
{
    return t1 < t2 ? t2 : t1;
}

ll val[5]={1,10,100,1000,10000};
ll dp[200005][7][2];
string s;

ll solve(int indx,int mx,int changed){
    if(indx==-1)return 0;
    else if(dp[indx][mx][changed]!=-1){
        return dp[indx][mx][changed];
    }

    else{
        ll res=0;
        int sign=1;
        if(s[indx]-'A'<mx){
            sign=-1;
        }
        res=sign*val[s[indx]-'A']+solve(indx-1,max(mx,int(s[indx]-'A')),changed);
        if(!changed){
            for(int i=0;i<5;i++){
                if(i!=s[indx]-'A'){
                    int sign=1;
                    if(i<mx){
                        sign=-1;
                    }
                    res=max(res,val[i]+solve(indx-1,max(mx,i),1));
                }
            }

        }
        dp[indx][mx][changed]=res;
        return res;

    }
}

int main() {
    fastio;

int t;
cin>>t;

while(t--){
    cin>>s;
    int n=s.size();
    memset(dp,-1,sizeof(dp[0])*(n+2));
    ll ans=solve(s.size()-1,0,0);
    cout<<ans<<endl;
}
return 0;
}