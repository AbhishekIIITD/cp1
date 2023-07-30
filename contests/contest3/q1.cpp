#include <bits/stdc++.h>
using namespace std;
int main() {

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string a="";
    int x=0;
    for(int i=1;i<n;i++){
        if(s[x]==s[i]){
            a+=s[i];
            x=i+1;
            i=i+1;
            
        }
    }
    cout<<a<<endl;
}
return 0;
}