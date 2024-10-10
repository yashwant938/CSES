#include<bits/stdc++.h>
// #define ll long long int
using namespace std;
int main(){
    int n;
    cin>>n;
    // ll x;
    // vector<ll>vec;
    // for(int i=0;i<n;i++){
    //     cin>>x;
    //     vec.push_back(x);
    // }
     if(n==2||n==3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
       for(int i=2;i<=n;i=i+2) {
        cout<<i<<" ";
    }
     for(int i=1;i<=n;i=i+2) {
        cout<<i<<" ";
    }
 
 
   
}