#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    int cnt=1;
    int ans=1;
    // cin.tie(0);

    // int t=
    for(int i=0;i<str.size()-1;i++){
        if(str[i]==str[i+1]){
            cnt+=1;
        }else{
            cnt=1;
        }
    ans=max(ans,cnt);
    }
    cout<<ans;
}