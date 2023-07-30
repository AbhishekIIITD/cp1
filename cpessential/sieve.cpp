#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int n){
    vector<int> primes(n+1,1);
    for(int i=2;i*i<n;i++){
        if(primes[i]==1){
            int j=i*i;
            while(j<n){
                primes[j]=0;
                j+=i;
            }
        }

    }
    return primes;
}
int main() {

int t;
cin>>t;

while(t--){

}
return 0;
}