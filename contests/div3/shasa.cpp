#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
 long long t;
cin>>t;
for(int k=0;k<t;k++){
  long long n;
  cin>>n;
  long long ans=0;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());

  int i=0,j=n-1;
while(i<n && j>0){
   if(i!=j && i<j){
ans+=arr[j]-arr[i];
i++;j--;
   }
   else if(i>=j )break;
  }
  cout<<ans<<endl;
}

return 0;
}