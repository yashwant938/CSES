/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int rev=0;
        int dig=0;
        int sum=0;
        while(n){
            rev=n%10;
            sum+=rev;
            dig=dig*10+rev;

            n=n/10;
        }
        cout<<sum<<endl;

    }
}
*/

//second
/*
#include<bits/stdc++.h>
int countSuneetWins(const vector<int>& sn, const vector<int>& sl) {
    int suneetWins = 0;
    for (int i = 0; i < 2; ++i) {  
        for (int j = 0; j < 2; ++j) { 
            int suneetCard1=sn[i];
            int suneetCard2=sn[1 - i];
            int slavicCard1=sl[j];
            int slavicCard2=sl[1 - j];
            int suneetRound1=suneetCard1>slavicCard1;
            int suneetRound2=suneetCard2>slavicCard2;
            if (suneetRound1+suneetRound2>1) {
                ++suneetWins;
            }
        }
    }
    return suneetWins;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int>sn(2);
        vector<int>sl(2);
        for (int i=0; i < 2; ++i) {
            cin>>sn[i];
        }
        for (int i = 0; i<2; ++i) {
           cin>>sl[i];
        }
       cout<<countSuneetWins(sn,sl)<<endl;
    }
    return 0;
}
*/
//third
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canShower(const vector<pair<int, int>>& t, int s, int m) {
    int prevEnd = 0;
    if (t.empty()) {
        return s <= m;
    }
    if (t[0].first >= s) {
        return true;
    }
    for (const auto& it : t) {
        if (it.first - prevEnd >= s) {
            return true;
        }
        prevEnd=it.second;
    }
    if (m-prevEnd>=s) {
        return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    int sum=0;
    for(int i=0;i<1000000;i++){
        sum+=i;
    }
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;
        vector<pair<int, int>> t(n);
        for (int i = 0; i < n; ++i) {
            cin >> t[i].first >> t[i].second;
        }
        if (canShower(t, s, m)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
*/
//fourth
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isSubsequence(const string& s, const string& t) {
    int n = s.length(), m = t.length();
    int j = 0; 
    for (int i = 0; i < n && j < m; ++i) {
        if (s[i] == t[j] || s[i] == '?') {
            ++j; 
        }
    }
    return j == m;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;

        if (isSubsequence(s, t)) {
            int n = s.length();
            int j = 0;

            for (int i = 0; i < n; ++i) {
                if (s[i] == '?') {
                    if (j < t.length() && (i < n && s[i] == t[j])) {
                        s[i] = t[j++];
                    } else {
                        s[i] = 'a'; 
                    }
                } else if (j < t.length() && s[i] == t[j]) {
                    ++j;
                }
            }

            cout << "YES\n" << s << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isSubsequence(const string& s, const string& t) {
    int n = s.length(), m = t.length();
    int j = 0; 
    for (int i = 0; i < n && j < m; ++i) {

        if (s[i] == t[j] || s[i] == '?') {
            ++j;
        }
    }

    return j == m;
}

int main() {
    int T;
    cin >> T; 
    while (T--) {
        string s, t;
        cin >> s >> t; 

        if (isSubsequence(s, t)) {
            int n = s.length();
            int j = 0; 

            for (int i = 0; i < n; ++i) {
                if (s[i] == '?') {
                    if (j < t.length()) {
                        s[i] = t[j++];
                    } else {
                        s[i] = 'a'; 
                    }
                } else if (j < t.length() && s[i] == t[j]) {
                    ++j; 
                }
            }

            cout << "YES\n" << s << "\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
*/

// #include <bits/stdc++.h>
// #define Code ios_base::sync_with_stdio(false);
// #define By cin.tie(NULL);
// #define yash cout.tie(NULL);
// #define endl "\n";
// using ll= long long;
// using lld=long double;
// using ull=unsigned long long;
// using namespace std;
// void solve(int l,int r){
//     unordered_map<int,int>st; 
//     queue<int>q;
//     q.push(r); 
//     st[r]=0; 
//     while(!q.empty()) {
//         int current=q.front();
//         q.pop();
//         if (current==0) {
//             return st[current];
//         }
//         int x=current / 3;
//         int y=current * 3;
//         if (x >= l && st.find(x) == st.end()) {
//             st[x] = st[current] + 1;
//             q.push(x);
//         }
//         // int sum=0;
//         // for(int i=0;i<1000000;i++){
//         //     sum+=i;
//         // }
//         if (y<=r&& st.find(y)==st.end()) {
//             st[y]=st[current] + 1;
//             q.push(y);
//         }
//     }
//     return -1; 
// }
// int main() {
//     Code By yash
//     int n;
//     cin>>n;
//     whiel(t--){
//         int a,b;
//         cin>>a>>b;
//         cout<<solve(a,b)<<endl;   
//     }
// }

//fifth
// #include <iostream>
// #include <queue>
// #include <unordered_map>
// using namespace std;
// int minO(int l, int r) {
//     unordered_map<int,int>st; 
//     queue<int>q;
//     q.push(r); 
//     st[r]=0; 
//     while(!q.empty()) {
//         int current=q.front();
//         q.pop();
        
//         if (current==0) {
//             return st[current];
//         }
//         int x=current / 3;
//         int y=current * 3;
//         if (x >= l && st.find(x) == st.end()) {
//             st[x] = st[current] + 1;
//             q.push(x);
//         }
//         int sum=0;
//         for(int i=0;i<1000000;i++){
//             sum+=i;
//         }
//         if (y<=r&& st.find(y)==st.end()) {
//             st[y]=st[current] + 1;
//             q.push(y);
//         }
//     }
//     return -1; 
// }

// int main() {
//     int t;
//     cin>>t;
//     while(t--){
//         int l,r;
//         cin>>l>>r;
//         int mini=minO(l, r);
//         cout<<mini<<endl;
//     }
//     return 0;
// }


