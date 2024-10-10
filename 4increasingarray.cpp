#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll x;
    vector<ll>vec;
    for(int i=0;i<n;i++){
        cin>>x;
        vec.push_back(x);
    }
    ll lmoves=0,moves=0;;
    for(int i=1;i<n;i++){
        if(vec[i-1]>vec[i]){
            lmoves+=abs(vec[i-1]-vec[i]);
            vec[i]+=lmoves;

            moves+=lmoves;
            
        }else{
            continue;
        }
        lmoves=0;
    }
    cout<<moves<<endl;
}