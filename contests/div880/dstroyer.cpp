#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    unordered_map<int,int> hash;
    int flg=1;
    ll total=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            total+=1;
            hash[0]+=1;
        }
        else{
            if(hash[arr[i]-1]!=0){
                total+=1;
                hash[arr[i]]++;
                hash[arr[i]-1]--;
            }
            else{
                flg=0;
                break;
            }
        }
    }
    if(flg&&total==n){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
return 0;
}