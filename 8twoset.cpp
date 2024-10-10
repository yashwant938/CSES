// #include<bits/stdc++.h>
// 
// using namespace std;
// int main(){
//     ll n,ss=0;
//     cin>>n;
//     ll  maxi=n;
//     vector<int>s1,s2;
//     vector<int>vec(n+1,0);
//     ll ts=(n*(n+1))/2;
//     // while()
//     if(ts%2!=0){
//         cout<<"NO"<<endl;
//     }else{
//         cout<<"YES"<<endl;
//         while(ss<ts/2){
//             ll rem=ts/2-ss;
//             if(rem>maxi){
//                 s1.push_back(maxi);
//                 vec[maxi]=1;
//                 s1=maxi;
//                 maxi--;
//             }
//         }
//     }

    
// }
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long total_sum = (long long)n * (n + 1) / 2;
    if (total_sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        long long target_sum = total_sum / 2;
        vector<int> set1, set2;
        long long sum1 = 0, sum2 = 0;
        for (int i = n; i >= 1; --i) {
            if (sum1 + i <= target_sum) {
                set1.push_back(i);
                sum1 += i;
            } else {
                set2.push_back(i);
                sum2 += i;
            }
        }
        cout << set1.size() << endl;
        for (int num : set1) {
            cout << num << " ";
        }
        cout << endl;
        cout << set2.size() << endl;
        for (int num : set2) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
