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
   
    ll n;
    cin>>n;
    vi vec(n);
    fo(i,n){
        cin>>vec[i];
    }
    ll cnt=0;
    for(int i=0;i<n-1;i++){
        int temp=0;
        if(vec[i]<=vec[i+1]){
            continue;
        }else{
            temp=vec[i]-vec[i+1];
            cnt+=temp;
            vec[i+1]=vec[i+1]+temp;
        }
    }
cout<<cnt<<endl;
   
    
}
