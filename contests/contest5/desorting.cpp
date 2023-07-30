#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    int last=0;
    int minDiff=INT_MAX;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(i==0){
            last=arr[i];
            continue;
        }
        minDiff=min(minDiff,arr[i]-last);
        last=arr[i];
    }
    if(minDiff<0){
        cout<<0<<endl;
    }
    else{
        cout<<((minDiff/2)+1)<<endl;
    }
    

}
return 0;
}