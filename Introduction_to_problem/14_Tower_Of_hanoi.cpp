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

void towerOfHanoi(int n,int from,int to,int aux,vector<pair<int,int>>&moves) {
    if (n==1){
        moves.push_back({from,to});
        return;
    }
    towerOfHanoi(n-1,from,aux,to,moves);
    moves.push_back({from, to});
    towerOfHanoi(n-1,aux,to,from,moves);
}
int main() {
    fast_io();
    int n;
    cin >> n;
    vector<pair<int, int>> moves;
    towerOfHanoi(n,1,3,2,moves);
    
    cout<<moves.size()<<"\n";
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << "\n";
    }
    
    return 0;
}