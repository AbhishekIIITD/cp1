#include <bits/stdc++.h>
using namespace std;



int main() {
    long long int n;
    long long int k;
    cin>>n>>k;
    pair<long long int,long long int> gifts[n];
    
    for(long long int i=0;i<n;i++){
        cin>>gifts[i].first;

    }
    for(long long int i=0;i<n;i++){
        cin>>gifts[i].second;

    }
    long long int i=0;
    long long int j=0;
    long long int minCost=0;
    long long int currCost=0;
    long long int currVal=0;
    while(j<n){
        
        if(currVal<k){
            currVal+=gifts[j].first;
            currCost+=gifts[j].second;
            j++;
        }
        else{
            
            currVal-=gifts[i].first;
            currCost-=gifts[i].second;
            i++;
        }

        if(currVal>=k){
            if(minCost==0){
                minCost=currCost;
            }
            else{
                minCost=min(currCost,minCost);
            }
        }
        
    }
   if(minCost==0){
    minCost=-1;
   }
    cout<<minCost<<endl;


return 0;
}
