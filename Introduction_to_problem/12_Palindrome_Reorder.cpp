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


int main(){
    string s;
    cin>>s;
    unordered_map<char,int>mpp;
    for(char c:s){
        mpp[c]++;
    }
    int cnt=0;
    char ch;
    for(auto x:mpp){
        if(x.second%2){
            ch=x.first;
            cnt++;

        }

    }
    if((s.size()%2==0 and cnt>0)or cnt>1){
        cout<<"NO SOLUTION";

    }else{
        string res="";
        for(auto x:mpp){
            for(int i=1;i<=x.second/2;i++){
                res+=x.first;
            }

        }
        cout<<res;
        if(s.size()%2)
            cout<<ch;
        reverse(res.begin(),res.end());
        cout<<res;
        
    }
    
    
}