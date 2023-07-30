#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(int n,ll k,vector<ll> &nums){
    vector<pair<int,queue<int>>> elements;
    sort(nums.begin(),nums.end());
    pair<int,queue<int>> firstElement;
    firstElement.first=nums[0];
    firstElement.second.push(0);
    elements.push_back(firstElement);
    int x=1;
    for(int i=1;i<n;i++){
        if(elements[x].first==nums[i]){
            elements[x].second.push(i);
        }
        else{
            pair<int,queue<int>> nextElement;
            nextElement.first=nums[i];
            nextElement.second.push(i);
            elements.push_back(nextElement);
            x++;
        }
        
    }
    //cout<<elements.size();
    priority_queue<pair<int,queue<int>>> pq;
    for(int i=0;i<n;i++){
        pq.push(elements[i]);
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int,queue<int>> maxElement=pq.top();
        int newEle=maxElement.first-k;
        if(newEle<=0){
            ans.push_back(maxElement.second.front());
            maxElement.second.pop();
            if(maxElement.second.size()==0){
                pq.pop();
            }

        }
        else{
            int indx=maxElement.second.front();
            int ele=maxElement.first-k;
            pair<int,queue<int>> element;
            element.first=ele;
            element.second.push(indx);
            maxElement.second.pop();
            pq.push(element);

        }
        cout<<maxElement.first<<endl;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

}
int main() {

int t;
cin>>t;

while(t--){
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    solve(n,k,nums);


}
return 0;
}