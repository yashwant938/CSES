#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll n;
    cin>>n;
    vector<ll>vec;
    while(n!=1){
        vec.push_back(n);
        if(n%2!=0){
            n=n*3+1;
            
        }else{
            n=n/2;
            // vec.push_back(n);
        }
    }
    vec.push_back(1);
    for(auto it:vec){
        cout<<it<<" ";
    }
}