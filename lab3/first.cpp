#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;
    int x=2*n-1;
    vector<int>arr(x,0);
    for(int i=0;i<(x-1);i++){
       int y;
        cin>>y; 
        arr[y]++;
    }
  sort(arr.begin(),arr.end());
  if(arr[arr.size()-1]==n-1){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;

}