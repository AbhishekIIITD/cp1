#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(int *a,int* b, int n){
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(a[i]> b[i]){
                ans += 1;
            }
        }
        return ans;
        }
int main() {

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    int *b=new int[n];
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    cout<<solve(a,b,n)<<endl;



}
return 0;
}