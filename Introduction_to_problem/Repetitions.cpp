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
   
    string str;
    cin>>str;
    int cnt=0;
    if(str.size()==1){
        cout<<1;
        return 0;
    }else if(str.size()==0){
        cout<<0;
        return 0;
    }
    int maxi=INT_MIN;
    for(int i=0;i<str.size()-1;i++){
        if(str[i]==str[i+1]){
            cnt++;
        }else{
         
            cnt=0;

        }
        maxi=max(maxi,cnt);
    }
    cout<<maxi+1;

   
    
}
