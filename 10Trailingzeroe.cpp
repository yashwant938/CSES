// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long int;
// int main(){
//     ll n;
//     cin>>n;
//     int x=n;
//     int sum=0;
//     int f=5;
//     while(x>=1){
//         sum+=n/f;
//         x=x/f;
//         f*=5;
        
//     }
//     cout<<sum<<endl;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
    ll n;
    cin >> n;

    ll countZeros = 0;
    ll factor = 5;

    while (n / factor > 0) {
        countZeros += n / factor;
        factor *= 5;
    }

    cout << countZeros << endl;

    return 0;
}
