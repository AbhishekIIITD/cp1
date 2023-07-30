#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    int nums[n];

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    sort(nums,nums+n,greater<int>());
    int k=nums[0];
    int ans=0;
    for(int i=0;i<n;i++){
        k--;
        if(k==0){
            ans++;
            if(i+1<n){
                k=nums[i+1];
            }
        }
        
    }
    cout<<ans<<endl;





}
return 0;
}