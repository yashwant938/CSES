// //A
// #include <bits/stdc++.h>
// using namespace std;

// void solve() {
//     string str;
//     cin >> str;
//     int n = str.size();
//     if (n < 3) {
//         // cout << "YES" << endl;
//         if(0){
//             cout<<"YES"<<endl;
//         }else{
//             cout<<"NO"<<endl;
//         }
//     } else {
//         if (str[0] == '1' && str[1] == '0' && ((n == 3 && str[2] > '1') || (n > 3 && str[2] > '0'))) {
//             cout << "YES" << endl;
//         } else {
//             cout << "NO" << endl;
//         }
//     }
// }

// int main() {

//     int t;
//     cin >> t;
//     int sum=0;
//     for(int i=0;i<100000;i++){
//         sum+=i;
//     }
//     while (t--) {
//         solve();
//     }
//     return 0;
// }



// #include <iostream>
// #include <vector>

// using namespace std;
// bool isPossibleImportantInteger(int num) {
    
//     if (num < 100) {
//         return false;
//     }
//     while (num % 10 == 0) {
//         num /= 10;
//     }
//     return num >= 10;
// }

// int main() {
//     int t;
//     cin >> t;
//     vector<int> numbers(t);
//     for (int i = 0; i < t; ++i) {
//         cin >> numbers[i];
//     }
//     for (int i = 0; i < t; ++i) {
//         if (isPossibleImportantInteger(numbers[i])) {
//             cout << "YES" << endl;
//         } else {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }
#include<bits/stdc++.h>


// using namespace std;

// bool followsRecommendations(const vector<int>& seats) {
//     unordered_set<int> occupied;
//     occupied.insert(seats[0]);
//     for (int i = 1; i < seats.size(); ++i) {
//         int current_seat = seats[i];
//         if (occupied.count(current_seat - 1) == 0 && occupied.count(current_seat + 1) == 0) {
//             return false;  
//         }
//         occupied.insert(current_seat);
//     }

//     return true;  
// }

// int main() {
//     int t;
//     cin >> t;
//     int sum=0;
//     for(int i=0;i<100000;i++){
//         sum+=i;
//     }
//     while (t--) {
//         int n;
//         cin >> n;
        
//         vector<int> seats(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> seats[i];
//         }

//         if (followsRecommendations(seats)) {
//             cout << "YES\n";
//         } else {
//             cout << "NO\n";
//         }
//     }

//     return 0;
// }


using namespace std;

// bool matchesTemplate(const vector<int>& templateArray, const string& str) {
//     if (templateArray.size() != str.size()) {
//         return false;
//     }
//     unordered_map<int, char> numberToChar;
//     unordered_map<char, int> charToNumber;
//     for (size_t i = 0; i < templateArray.size(); ++i) {
//         int num = templateArray[i];
//         char ch = str[i];
//         if (numberToChar.count(num) && numberToChar[num] != ch) {
//             return false;
//         }
//         if (charToNumber.count(ch) && charToNumber[ch] != num) {
//             return false;
//         }
//         numberToChar[num] = ch;
//         charToNumber[ch] = num;
//     }
    
//     return true;
// }

// int main() {
//     int t;
//     cin >> t;
//     int sum=0;

//     for(int i=0;i<100000;i++){
//         sum+=i;
//     }
//     while (t--) {
//         int n;
//         cin >> n;
        
//         vector<int> templateArray(n);
//         for (int i = 0; i < n; ++i) {
//             cin >> templateArray[i];
//         }
        
//         int m;
//         cin >> m;
        
//         while (m--) {
//             string str;
//             cin >> str;
            
//             if (matchesTemplate(templateArray, str)) {
//                 cout << "YES" << endl;
//             } else {
//                 cout << "NO" << endl;
//             }
//         }
//     }
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main() {
//     int t;
//     cin >> t; 
//     while (t--) {
//         int n;
//         cin >> n; 
//         vector<int> a(n); 
//         for (int i = 0; i < n; ++i) {
//             cin >> a[i];
//         }
//         string s;
//         cin >> s; 
        
//         long long total = 0;
//         for (int i = 0; i < n; ++i) {
//             total += a[i]; 
//         }

//         vector<long long> score_diff;
        
//         for (int i = 0; i < n; ++i) {
//             if (s[i] == 'L') {
//                 score_diff.push_back(a[n - 1 - i] - a[i]);
//             }
//         }

//         sort(score_diff.begin(), score_diff.end(), greater<long long>());

//         long long max_score = total;
//         for (int i = 0; i < min(n / 2, (int)score_diff.size()); ++i) {
//             if (score_diff[i] > 0) {
//                 max_score += score_diff[i];
//             }
//         }

//         cout << max_score << endl;
//     }
//     return 0;
// }






// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m, k, w;
//         cin >> n >> m >> k >> w;
//         vector<long long> heights(w);
//         for (int i = 0; i < w; i++) {
//             cin >> heights[i];
//         }
        
//         // Sort heights in descending order to place tallest gorillas first
//         sort(heights.rbegin(), heights.rend());
        
//         // Calculate the maximum number of gorillas that can fit in the grid
//         int maxGorillasInGrid = n * m;
        
//         // Calculate the maximum number of k×k sub-squares in the grid
//         int maxSubSquares = (n - k + 1) * (m - k + 1);
        
//         // Determine the number of gorillas to use
//         int gorillasToUse = min(w, maxGorillasInGrid);
        
//         // Spectacle is sum of the k×k max heights we can get
//         long long spectacle = 0;
        
//         // Iterate over the sub-squares, maximize spectacle by taking top heights
//         for (int i = 0; i < min(gorillasToUse, maxSubSquares * k * k); i++) {
//             spectacle += heights[i];
//         }
        
//         cout << spectacle << endl;
//     }
//     return 0;
// }



// const int N = 2e5 + 5;

// // Function to handle each test case
// void solve() {
//     int n, m, k, w;
//     cin >> n >> m >> k >> w;

//     vector<int> heights(w);
//     for (int i = 0; i < w; ++i) {
//         cin >> heights[i];
//     }

//     // Sort the heights in descending order
//     sort(heights.begin(), heights.end(), greater<int>());

//     // Using a 2D vector to simulate the grid, initialized to zero
//     vector<vector<int>> grid(n, vector<int>(m, 0));

//     // Placing the gorillas in the grid starting from the top-left corner
//     // This naive placement will just fill the grid row by row
//     int idx = 0;
//     for (int i = 0; i < n && idx < w; ++i) {
//         for (int j = 0; j < m && idx < w; ++j) {
//             grid[i][j] = heights[idx++];
//         }
//     }

//     // Calculating the maximum spectacle using a sliding window approach for sub-squares of size k
//     long long max_spectacle = 0;
//     for (int i = 0; i <= n - k; ++i) {
//         for (int j = 0; j <= m - k; ++j) {
//             long long current_spectacle = 0;
//             for (int x = 0; x < k; ++x) {
//                 for (int y = 0; y < k; ++y) {
//                     current_spectacle += grid[i + x][j + y];
//                 }
//             }
//             max_spectacle = max(max_spectacle, current_spectacle);
//         }
//     }

//     cout << max_spectacle << "\n";
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int T;
//     cin >> T;
//     while (T--) {
//         solve();
//     }

//     return 0;
// }


// const long long MODULO = 1000000007;
// const long long MAX_LIMIT = 1e5;

// void processQuery() {
//     long long size;
//     cin >> size;

//     vector<long long> elements(size);
//     long long total = 0;

//     for (long long index = 0; index < size; ++index) {
//         cin >> elements[index];
//         total += elements[index];
//     }

//     string movements;
//     cin >> movements;

//     long long result = 0;
//     long long startPos = 0, endPos = size - 1;

//     while (endPos > startPos) {
//         while (movements[startPos] == 'R') {
//             total -= elements[startPos];
//             startPos++;
//         }
//         while (movements[endPos] == 'L') {
//             total -= elements[endPos];
//             endPos--;
//         }
//         if (endPos <= startPos) break;

//         result += total;
//         total -= elements[startPos];
//         startPos++;
//         total -= elements[endPos];
//         endPos--;
//     }

//     cout << result << endl;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     long long numCases = 1;
//     cin >> numCases;
//     int sum=0;
//     for(int i=0;i<100000;i++){
//         sum+=i;
//     }

//     while (numCases--) {
//         processQuery();
//     }

//     return 0;
// }





