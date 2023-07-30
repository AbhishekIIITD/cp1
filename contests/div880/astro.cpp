#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll max(ll a,ll b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}
int main() {

int t;
cin>>t;

while(t--){
    ll n,k,g;
    cin>>n>>k>>g;
    ll ans=0;
    ll r=ceil(g/2);
    ll curr=(r-1)*(n-1);
    if(curr>=k*g){
        ans=k*g;
    }
    else{
        if((k*g-curr)%g<r){
            ans=curr+(k*g-curr)%g;
        }
        else{
            ans=curr-g+r;
        }
    }
    cout<<max(0,ans)<<endl;
    


}
return 0;
}