#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define fo(i, n) for(int i=0;i<n;i++)
#define fo1(i, n) for(int i=1;i<=n;i++)
#define sortall(x) sort(all(x))
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define fast_io() ios::sync_with_stdio(0); cin.tie(0);
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