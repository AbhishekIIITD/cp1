#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool check(ll mid,vector<int> &arr,int k){
    int n=arr.size();
    int totalDays=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>mid){
            continue;
        }
        int days=(mid-arr[i])/(i+1);//no of days it would be contributing to remove eles before mid;
        days++;
        totalDays+=days;
        mid-=(days*(i+1));
        if(mid<0){
            return false;
        }
    }
    return (totalDays>k);
}
ll solve(int n,int k,vector<int> moves){
    if(moves[0]!=1){
        return 1;

    }
    else{
        int si=1;
        ll ei=1e12;
        ll ans=1;
        while(si<=ei){
            ll mid=(si+ei)/2;
            if(check(mid,moves,k)){
                ans=mid;
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
            cout<<mid<<endl;
        }
        return ans;
    }
}

int main() {

int t;
cin>>t;

while(t--){
    ll n,k;
    cin>>n>>k;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(n,k,arr)<<endl;
    


}

return 0;
}