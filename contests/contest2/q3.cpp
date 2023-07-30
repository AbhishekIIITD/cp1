#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int n){
    vector<int> primes(n,1);
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i<n;i++){
        if(primes[i]==1){
            int j=i*i;
            while(j<n){
                primes[j]=0;
                j=j+i;
                cout<<j<<endl;
            }
            
        }

    }
    return primes;
}
int main() {

int t;
cin>>t;
vector<int> primes=sieve(1000);

while(t--){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j]=0;
        }
    }
    for(int x=1;x<m*n;x++){
        int filled=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    if(i-1>0&&arr[i-1][j]!=0&&primes[abs(arr[i][j]-arr[i-1][j])]){
                        continue;
                    }
                    else if(i+1<n&&arr[i+1][j]!=0&&primes[abs(arr[i][j]-arr[i+1][j])]){
                        continue;
                    }
                    else if(j-1>0&&arr[i][j-1]!=0&&primes[abs(arr[i][j]-arr[i][j-1])]){
                        continue;
                    }
                    else if(j+1<m&&arr[i][j+1]!=0&&primes[abs(arr[i][j]-arr[i][j+1])]){
                        continue;

                    }
                    else{
                        arr[i][j]=x;
                        filled=1;
                        break;

                    }
                    
                }
                
            }
            if(filled){
                break;
            }

        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
return 0;
}