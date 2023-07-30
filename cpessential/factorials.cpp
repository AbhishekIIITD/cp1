#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll* factorials(int n){
    ll* fact=new ll[n];
    fact[0]=1;
    for(int i=1;i<n;i++){
        ll curr=(i*fact[i-1])%mod;
        fact[i]=curr;
    }
    return fact;
}

int main() {


return 0;
}