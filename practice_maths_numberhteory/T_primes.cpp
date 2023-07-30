#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> sieve(int n){
    vector<int> primes(n+1,1);
    primes[0]=primes[1]=0;
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

    int n;
    cin>>n;
    ll *arr=new ll[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> primes=sieve(1000000);
    unordered_map<ll,int> hash;
    for(ll i=0;i<1000000;i++){
        if(primes[i]==1){
            hash[i*i]=1;
        }
    }
    for(ll i=0;i<n;i++){
        if(hash[arr[i]]==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
return 0;
}