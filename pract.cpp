#include <bits/stdc++.h>
// using namespace std;

// // int main() {
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         long long n, m, k;
// //         cin >> n >> m >> k;
// //         long long sol = min(n, k) * min(m, k);
// //         cout << sol << endl;
// //     }

// //     return 0;
// // }

// // int main(){
// //     int t;
// //     cin>>t;
// //     while(t--){

// //     }
// // }
// // #include <iostream>
// // using namespace std;

// // int main() {
// //     int t;
// //     cin >> t;
// //     while (t--) {
// //         int n, m, k;
// //         cin >> n >> m >> k;

// //         // Calculate the minimum number of colors needed
// //         int colors = k * k;
        
// //         cout << colors << endl;
// //     }
// //     return 0;
// // }


// // using namespace std;

// int main() {
//     int t;
//     cin >> t; 

//     while (t--) {
//         int n;
//         cin >> n; 

//         vector<int> a(n);
//         vector<int> b(n);

//         for (int i = 0; i < n; ++i) {
//             cin >> a[i]; 
//         }
//         for (int i = 0; i < n; ++i) {
//             cin >> b[i]; 
//         }
//         unordered_set<int> alice_choices;
//         unordered_set<int> bob_choices;
//         alice_choices.insert(a.front());

//         alice_choices.insert(a.back());
//         bob_choices.insert(b.front());
//         bob_choices.insert(b.back());
//         bool alice_wins = false;
//         for (int num : alice_choices) {
//             if (bob_choices.find(num) == bob_choices.end()) {
//                 alice_wins = true;
//                 break;
//             }
//         }
//         if (alice_wins) {
//             cout << "Alice" << endl;
//         } else {
//             cout << "Bob" << endl;
//         }
//     }

//     return 0;
// }
// #include <iostream>
// #include <vector>

// using namespace std;
// long long a[400005], b[400005], c[400005];

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     long long t, n;
//     cin >> t;

//     while (t--) {
//         long long check = 1;
//         cin >> n;
//         for (int i = 1; i <= n; i++) {
//             c[i] = 0;
//         }
//         for (int i = 1; i <= n; i++) {
//             cin >> a[i];
//             c[n - i + 1] += a[i];
//         }
//         for (int i = 1; i <= n; i++) {
//             cin >> b[i];
//             if (b[i] != a[i]) {
//                 check = 0;
//             }
//         }

//         if (check == 0) {
//             check = 1;
//             for (int i = 1; i <= n; i++) {
//                 if (b[i] != c[i]) {
//                     check = 0;
//                     break;
//                 }
//             }
//         }

//         if (check) {
//             cout << "Bob\n";
//         } else {
//             cout << "Alice\n";
//         }
//     }

//     return 0;
// }



// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;

//         vector<pair<int, int>> circles(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> circles[i].first >> circles[i].second;
//         }
//         int xs, ys, xt, yt;
//         cin >> xs >> ys >> xt >> yt;
//         double d = sqrt((xt - xs) * (xt - xs) + (yt - ys) * (yt - ys));
//         bool possible = true;
//         for (int i = 0; i < n; ++i) {
//             int cx = circles[i].first, cy = circles[i].second;
//             double startDist = sqrt((cx - xs) * (cx - xs) + (cy - ys) * (cy - ys));
//             double endDist = sqrt((cx - xt) * (cx - xt) + (cy - yt) * (cy - yt));

//             if (startDist <= d && endDist <= d) {
//                 possible = false;
//                 break;
//             }
//         }

//         if (possible) {
//             cout << "YES\n";
//         } else {
//             cout << "NO\n";
//         }
//     }

//     return 0;
// }

using namespace std;
typedef long long ll;
ll squaredDistance(ll xStart, ll yStart, ll xEnd, ll yEnd) {
    ll diffX = xEnd - xStart;
    ll diffY = yEnd - yStart;
    return diffX * diffX + diffY * diffY;
}

int main() {
    ll testCases;
    cin >> testCases;
    while (testCases--) {
        ll numPoints;
        cin >> numPoints;
        vector<ll> coordX(numPoints), coordY(numPoints);
        
        for (ll index = 0; index < numPoints; ++index) {
            cin >> coordX[index] >> coordY[index];
        }

        ll startX, startY, destX, destY;
        cin >> startX >> startY >> destX >> destY;
        ll comparisonDistance = squaredDistance(startX, startY, destX, destY);
        
        bool closerFound = false;
        for (ll index = 0; index < numPoints; ++index) {
            if (comparisonDistance >= squaredDistance(coordX[index], coordY[index], destX, destY)) {
                closerFound = true;
                break;
            }
        }

        for (ll i = 0; i < 100000; ++i) {
            ll temp = sqrt(i);
        }

        if (closerFound) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
