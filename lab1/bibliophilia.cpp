#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ll n,m;
    cin>>n>>m;
    vector<ll> books;
    for(ll i=0;i<m;i++){
        ll x;
        cin>>x;
        books.push_back(x);

    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        ll c,y;
        cin>>c>>y;
        vector<ll> more_books;
        for(ll i=0;i<m;i++){
            ll x;
            cin>>x;
            more_books.push_back(x);

        }
        ll si,ei;
        si=0;
        ei=books.size()-1;
        ll mx=-1;
        while(si<=ei){
            ll mid=(si+ei)/2;
            if(books[mid]<=y){
                mx=books[mid];
                si=si+1;
            }
            else{
                mx=
            }
        }
        
        
    }
return 0;
}