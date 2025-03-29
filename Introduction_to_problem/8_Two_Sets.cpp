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
   ll total_sum=(ll)n*(n+1)/2;
   if(total_sum%2!=0){
    cout<<"NO"<<endl;
   }else{
    cout<<"YES"<<endl;
  
   ll target_sum=total_sum/2;
   vi set1,set2;
   ll sum1=0,sum2=0;
   for(int i=n;i>=1;--i){
    if(sum1+i<=target_sum){
        set1.push_back(i);
        sum1+=i;
    }else{
        set2.push_back(i);
        sum2+=i;
    }
   }
   cout<<set1.size()<<endl;
   for(int num:set1){
    cout<<num<<" ";
   }
   cout<<endl;
   cout<<set2.size()<<endl;
   for(int num:set2){
    cout<<num<<" ";
   }
   cout<<endl;
}
   return 0;
}
  
    

