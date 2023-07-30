#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
t=1;
while(t--){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int ans=0;
    int i=0;int j=0;
    while(i<n&&j<n){
        if(s[i]!='0'){
            i++;
        }
        else if(t[j]!='0'){
            j++;
        }
        else{
            if(i!=j){
                ans++;
                i++;
                j++;
            }
            else{
                i++;
                j++;
            }
        }

    }
    int n1=0;int n2=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            n1++;
        }
        if(t[i]=='0'){
            n2++;
        }
    }
    if(n1!=n2){
        ans=-1;
    }
    cout<<ans<<endl;
}
return 0;
}