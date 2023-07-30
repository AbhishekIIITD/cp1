#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {

int t;
cin>>t;
while(t--){
    string x,y;
    cin>>x>>y;
    ll ans=0;
    int i=0;int j=0;int flg=0;
    while(y.size()-j>x.size()){
        ans+=(int(y[j])-48);
        ans+=9*(y.size()-1);
        flg=1;
        break;
    }
    
    while(i<x.size()&&flg==0){
        if(int(x[i])==int(y[i])){
            i++;
            j++;
        }
        else{
            ans+=abs(int(x[i])-int(y[i]));
            ans+=9*(x.size()-i-1);
            break;
        }
    }
    
    cout<<ans<<endl;
}


return 0;
}