#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;

while(t--){
    int n,m,h;
    cin>>n>>m>>h;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[m];
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    pair<int,int> results[n];

    for(int i=0;i<n;i++){
        sort(arr[i],arr[i]+m);
        
        for(int j=0;j<m;j++){
            
        }
    }
}
return 0;
}