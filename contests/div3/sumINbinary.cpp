#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;

while(t--){
    ll n;
    cin>>n;
    ll ans=0;
    while(n>0){
        ans+=n;
        n=n/2;
    }
    cout<<ans<<endl;
}
return 0;
}