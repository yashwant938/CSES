#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
     ll n;
     cin>>n;
     vector<ll>vec;
     ll x;
     for(int i=0;i<n-1;i++){
        cin>>x;
        vec.push_back(x);
     }
     ll sum=n*(n+1)/2;
     ll sum2=0;
     for(int i=0;i<n-1;i++){
        sum2+=vec[i];
     }
     cout<<sum-sum2<<endl;
}