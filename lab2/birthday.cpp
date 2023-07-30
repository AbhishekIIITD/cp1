#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maximum = 1e12+1;
ll mini(ll a,ll b){
    if(a<b){
        return a;

    }
    else{
        return b;
    }
}
bool compareGifts(pair<ll,ll> x, pair<ll,ll> y){
    return x.second < y.second;
}

double solve(pair<ll,ll> *gifts, ll n, ll k, double **dp){
    if(n == 0 && k <= 0){
        return 0;
    }
    else if(k>0&&n==0){
        return maximum;
    }else if(k==0){
        return dp[n][k]=min(gifts[0].first,gifts[0].second)+solve(gifts + 1, n - 1, k, dp);
    }
   
    else if(dp[n][k] != -1){
        return dp[n][k];
    }
    else{
        double smallAns = solve(gifts + 1, n - 1, k, dp)+gifts[0].first;
        double smallAns2 = solve(gifts + 1, n - 1, k - 1, dp)+gifts[0].second ;
        dp[n][k]=min(smallAns,smallAns2);
        return dp[n][k];
        
    }
}

int main() {
    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;
        double** dp = new double*[n+1];
        for(ll i = 0; i <= n; i++){
            dp[i] = new double[k+1];
            for(ll j = 0; j <= k; j++){
                dp[i][j] = -1;
            }
        }
        pair<ll,ll> gifts[n];
        for(ll i = 0; i < n; i++){
            cin >> gifts[i].first;
            cin >> gifts[i].second;
        }
        double ans = solve(gifts, n, k, dp);
        cout << ans << endl;
        for(ll i = 0; i <= n; i++){
            delete[] dp[i];
        }
        delete[] dp;
    }
    return 0;
}
