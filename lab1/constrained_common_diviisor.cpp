#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }


vector<ll> findDivisors(ll N) {
    vector<ll> divisors;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            divisors.push_back(i);
            if (i != N / i) {
                divisors.push_back(N / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}
ll find_common_divisor(ll L,ll R,vector<ll> divisors){
    ll ans=-1;
    ll si=0;
    ll ei=divisors.size()-1;
    while(si<=ei){
        ll mid=(si+ei)/2;
        if(divisors[mid]>=L&&divisors[mid]<=R){
            ans=divisors[mid];
            si=mid+1;

        }
        else if(divisors[mid]<L){
            si=mid+1;
        }
        else {
            ei=mid-1;
        }

    }
    return ans;
}

int main() {
    ll a, b;
    cin >> a >> b;
    
    ll n;
    cin >> n;

    ll gcdN=gcd(max(a,b),min(a,b));
    vector<ll> divisors=findDivisors(gcdN);
  

    
    for (ll i = 0; i < n; i++) {
        ll L, R;
        cin >> L >> R;
        ll result = find_common_divisor( L, R,divisors);
        cout << result << "\n";
    }
    return 0;
    
}