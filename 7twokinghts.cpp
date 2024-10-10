#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll solve(ll k){
    ll t=(k*k*(k*k-1))/2;
    ll a=4*(k-1)*(k-2);
    ll ans=t-a;
    return ans;
}
int main(){
    ll n;
    cin>>n;
    for(int k=1;k<=n;k++){
        cout<<solve(k)<<" ";
    }
    
}