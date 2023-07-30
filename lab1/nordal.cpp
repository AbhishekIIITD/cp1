#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {

int n;
cin>>n;
int *arr=new int[n];
ll ans=0;

for(int i=0;i<n;i++){
    cin>>arr[i];
    ans+=arr[i]-1;
}
cout<<ans;


return 0;
}