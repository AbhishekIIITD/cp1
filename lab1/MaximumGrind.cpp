#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main() {

int n;
cin>>n;
int maximum_score=0;
unordered_map<string,int> hash;
for(int i=0;i<n;i++){
    string s;
    int rating;

    cin>>s>>rating;
    int score;

    if(rating<1100){
        score=0;
    }
    else if(rating <1300){
        score=1;
    }
    else{
        score=2+(rating-1300)/200;

    }
    hash[s]=hash[s]+score;
    maximum_score=max(maximum_score,hash[s]);

}
    cout<<maximum_score;
return 0;
}