#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {

int t;
cin>>t;

while(t--){
    ll n,k;
    cin>>n>>k;
    ll x=log2(n);
    ll ans=0;
    ll y=x-1;
    ll z=pow(2,x)+pow(2,y);
    while(z>k&&y>=0){
        y--;
        ll z=pow(2,x)+pow(2,y);

    }
    ans=pow(2,x);
    if(y>=0){
        ans+=pow(2,y+1);
    }
    cout<<ans<<endl;

}
return 0;
}