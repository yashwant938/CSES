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
vector<string> generateGrey(int n){
    vector<string> gray;
    for(int i=0;i<(1<<n);i++){
        int greyCOde=i^(i>>1);
        string binary=bitset<16>(greyCOde).to_string(); 
        gray.push_back(binary.substr(16-n)); 
    }
    return gray;
}

int main(){
    
    fast_io() 
    int n;
    cin>>n;
    vector<string> result=generateGrey(n);
    for(const string &s: result){
        cout<<s<<endl;
    }
    return 0;
    
}