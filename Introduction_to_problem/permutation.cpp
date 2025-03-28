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


int main() {
    fast_io();
   int n;
   cin>>n;
   if(n==1){
    cout<<1;
    return 0;
   }
   if(n==2||n==3){
    cout<<"NO SOLUTION";
    return 0;
   }
   for(int i=2;i<=n;i+=2){
    cout<<i<<" ";
    
   }
   for(int i=1;i<=n;i+=2){
    cout<<i<<" ";
   }
   

    
}
