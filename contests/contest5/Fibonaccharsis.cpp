#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(ll x,ll y,ll n){
    if(n==1){
        return true;
    }
    
    else{
        ll newX=y-x;
        
        if(newX>=0&&newX<=x){
            return isValid(newX,x,n-1);
        }
        return false;
    }
}

ll lowest(ll si,ll ei,ll n,ll k){
    
    if(si>ei){
        return 1e9+2;
    }
    ll ans=1e9+2;
    
   ll mid=(si+ei)/2;
   
    if(isValid(mid,n,k-1)){
        ll smallAns1=lowest(si,mid-1,n,k);
        ans=min(ans,min(mid,smallAns1));
        
    }
    else{
        ll smallAns1=lowest(si,mid-1,n,k);
        ll smallAns2=lowest(mid+1,ei,n,k);
        ans=min(ans,min(smallAns1,smallAns2));
    }
    return ans;
}
ll highest(ll si,ll ei,ll n,ll k){
    if(si>ei){
        return -1;
    }
    ll ans=-1;
    
   ll mid=(si+ei)/2;
   //cout<<si<<" "<<ei<<" "<<mid<<endl;
    if(isValid(mid,n,k-1)){
        ll smallAns1=highest(mid+1,ei,n,k);
        ans=max(mid,max(smallAns1,ans));
        
    }
    else{
        ll smallAns1=highest(mid+1,ei,n,k);
        ll smallAns2=highest(si,mid-1,n,k);
        ans=max(ans,max(smallAns1,smallAns2));
    }
    return ans;
}


int main() {

int t;
cin>>t;

while(t--){
    ll n,k;
    cin>>n>>k;
    ll low=lowest(0,n,n,k);
    ll high=highest(0,n,n,k);
    ll ans=0;
    //cout<<high<<" "<<low<<endl;
    if(low<=high){
        ans=high-low+1;
    }
    cout<<ans<<endl;
    

}
return 0;
}