#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int find_not_div(int n){
    for(int i=1;i<n;i++){
        if(n%i!=0){
            return i;
        }
    }
    return -1;
}

void solve(int n){
    if(n==1){
        cout<<"a"<<endl;
        return;
    }
    else if(n==2){
        cout<<"ab"<<endl;
        return;
    }
    else if(n==3){
        cout<<"aba"<<endl;
        return;
    }
    char curr=97;
    vector<char> ans(n,96);
    int not_div=find_not_div(n);
    int i=0;
    while(i<n){
        if(ans[i]<97){
            int j=i;
            
            while(j<n){
                ans[j]=curr;
                j+=not_div;
            }
            curr++;
        }
        i++;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    cout<<endl;

}
int main() {

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    solve(n);

}
return 0;
}