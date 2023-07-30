#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll mod=1e9+7;

ll* factorials(int n){
    ll* fact=new ll[n];
    fact[0]=1;
    for(int i=1;i<n;i++){
        ll curr=(i*fact[i-1])%mod;
        fact[i]=curr;
    }
    return fact;
}
ll sum(ll num){
    if((num/10)==0){
        return num;
    }
    else{
        ll ans=0;
        while(num!=0){
            ans+=num%10;
            num=num/10;
        }
        return sum(ans);
    }
}
int main() {
    int a,b,n;
    cin>>a>>b>>n;
    ll *fact=factorials(n);
    for(int i=0;i<n;i++){
        
    }
    



return 0;
}