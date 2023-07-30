#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;

while(t--){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> seg(m);

    for(int i=0;i<m;i++){
        cin>>seg[i].first>>seg[i].second;
        seg[i].first--;
        seg[i].second--;
    }
    int q;
    cin>>q;
    vector<int> arr(n,0);
    int ans=-1;
    int indx=0;
    bool flag=false;
    while(q--){
        indx++;
        int x;
        cin>>x;
        arr[x-1]=1;
        vector<int> pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<pre.size();i++){
            pre[i]=pre[i-1]+arr[i];
            //cout<<pre[i]<<" ";
        }
        for(int i=0;i<seg.size();i++){
            int val=0;
            if(seg[i].first==0){
                val=pre[seg[i].second];
            }
            else{
                val=pre[seg[i].second]-pre[seg[i].first-1];
            }
            if((val>((seg[i].second-seg[i].first+1)/2))&&(flag==false)){
                flag=true;
                ans=indx;
            }
            //cout<<seg[i].first<<" "<<seg[i].second<<" "<<val<<endl;
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }
    else{
        cout<<ans<<endl;
    }

}
return 0;
}