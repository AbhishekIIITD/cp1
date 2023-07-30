#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t=1;

while(t--){
    ll x,y;
    cin>>x>>y;
    ll ans=0;
    if(x>=0&&y>=0){
        if(y>=x){
            ans+=(y-x);
        }
        else if(y==0){
            ans+=(x+1);
        }
        else{
            ans+=(x-y+2);
        }
    }
    else if(x<=0&&y<=0){
        if(y>=x){
            ans+=(y-x);
            
        }
        else if(x==0){
            ans+=((-1*y)+1);
        }
        else{
            ans+=(x-y+2);
        }
    }
    else{
        ans+=abs(max(x,y)+min(x,y))+1;
    }
    cout<<ans<<endl;
}
return 0;
}